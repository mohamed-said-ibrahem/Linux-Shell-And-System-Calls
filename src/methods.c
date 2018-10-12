#include "../helper/methods.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h> /* pid_t */
#include <errno.h>   /* errno */
#include <sys/types.h>
#include <sys/wait.h>


char commandsArr[1000][25];
int commandsCounter = 0;
int backgroundExecution;
int valid;


int checkBackgroundExecution(char *command){
	int len = strlen(command);
	if(command[len-1] == '&'||command[len-2] == '&'){
		return 1;
	}else{
		return 0;
	}
}


char *removeWhiteSpaces(char *command){
	   int length, indexA, indexB ,indexC;
	   char *modifiedCommand;
	   indexA = 0;
	   indexB = 0;
	   indexC = 0;

	   length = strlen(command);

	   modifiedCommand = (char*) malloc (length+1);

	   if (modifiedCommand == NULL)
	      exit(1);

	   while (*(command+indexA) != '\0') {
	      if (*(command+indexA) == ' ') {
	         int temp = indexA + 1;
	         if (*(command+temp) != '\0') {
	            while (*(command+temp) == ' ' && *(command+temp) != '\0') {
	               if (*(command+temp) == ' ') {
	                  indexA++;
	               }
	               temp++;
	            }
	         }
	      }
	      *(modifiedCommand+indexB) = *(command+indexA);
	      indexA++; indexB++;
	   }
	   *(modifiedCommand+indexB)= '\0';
	   if(*(modifiedCommand+indexC)== ' '){
		   while (*(modifiedCommand+indexC) != '\0') {
			   *(modifiedCommand+indexC) = *(modifiedCommand+indexC+1);
			   indexC++;
		   }
	   }
	   return modifiedCommand;

};


char *trimWhiteSpaces(char *str)
{
  char *end;

  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)return str;

  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  end[1] = '\0';

  return str;
}


void parseCommandInsideAsingleArray(char *command,char **arr){
	     while (*command != '\0') {
	          while (*command == ' ' || *command == '\t' || *command == '\n')
	               *command++ = '\0';
	          *arr++ = command;
	          while (*command != '\0' && *command != ' ' &&
	                 *command != '\t' && *command != '\n')
	        	  command++;
	     }*arr = '\0';
	 	printf(*arr);

}


void parseCommand(char *command){

	char *token;
	commandsCounter = 0;
	command = removeWhiteSpaces(command);
	backgroundExecution = checkBackgroundExecution(command);

	token = strtok(command," ");

	while( token != NULL ) {

	  strcpy(commandsArr[commandsCounter],token);

	  commandsCounter++;

	  token = strtok(NULL, " ");
	}

};


void exitProcess(int status){
	exit(status);
};


void startShell(){


};


int cdCommand(char *pth){
    char cwd[400];
    char path[400];
    strcpy(path,pth);

    if(pth[0] != '/')
    {
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,path);
        chdir(cwd);
    }else{
        chdir(pth);
    }
	printf("%s",getcwd(cwd,sizeof(cwd)));

    return 0;
}


void executeShellBuiltInCommands(char *command,char *args[]){
	if(strcmp(command,"cd") == 0){
		cdCommand(commandsArr[1]);
	}else{
		//example-> "times","dirs","help","eval",....
		// list of all Built-In mehods  https://docstore.mik.ua/orelly/linux/lnut/ch07_07.htm
		char *head = "bash -c ";
	    char *result = malloc(strlen(head) + strlen(command) + 1); // +1 for the null-terminator
	    strcpy(result, head);
	    strcat(result, command);

	    printf("command is:\n");
	    printf("%s",result);
	    printf("\n\n");
		system(result);
	}
};



void signalHandler(int signal)
{
	printf("\nCought signal %d!\n",signal);
	if (signal==SIGCHLD) {
		printf("\nChild ended\n");
		writeInLogFille("child process was terminated");

	}
}


void execute(char **args){
	signal(SIGCHLD,signalHandler);
	pid_t pid;
	if(strcmp(commandsArr[0],"exit") == 0){
		exitProcess(0);
	}

	pid = fork();

	if(pid < 0){
	      printf("ERROR CAN'T FORK() \n");
	      exitProcess(errno);
	}
	if(pid == 0){
	  /* Child process:
	   * When fork() returns 0, we are in
	   * the child process.
	   */
		printf("\nChild running...\n");

		 valid = execvp(commandsArr[0],args);
		 printf("\n");
		if(valid < 0){executeShellBuiltInCommands(commandsArr[0],args);}
//		sleep(2);
//		kill(getppid(),SIGCHLD);
		printf("\nChild exitting...\n");


	}
	if(!backgroundExecution){
	  /* When fork() returns a positive number, we are in the parent process
	   * (the fork return value is the PID of the newly created child process)
	   */
		int status;

		printf("\nParent Running, PID=%d.\n",getpid());

		do{
			waitpid(pid,&status,WUNTRACED|WNOHANG);
		}while(!WIFSIGNALED(status)&&!WIFEXITED(status));
		printf("\nParent ended, PID=%d.\n",getpid());

			// WIFEXITED(status) Normally  WIFSIGNALED signal
			//if the child process terminated by signal or normally
			//the parent should wait as it is not run in background process
			//run in back-ground is the process which you need to wait until the current child if exists finishs
			//and then you need to work with the parent to execute the background-commands
			//background --> parent  any other commands --> child(s)
			//child end with signal which is SIGCHLD

			//if(valid <0){exitProcess(1);}
	}

};


void writeInLogFille(char *text){

	FILE *f = fopen("file.txt", "a");
	if (f == NULL)
	{
	    printf("\n Error Opening File! \n");
	    exit(1);
	}

	fprintf(f,text);

	fclose(f);
	printf("\n File Closed \n");

};

