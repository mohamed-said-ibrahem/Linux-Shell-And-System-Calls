#include "../helper/methods.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h> /* pid_t */
#include <errno.h>   /* errno */

char commandsArr[1000][25];
int commandsCounter = 0;
int backgroundExecution;

int checkBackgroundExecution(char *command){
	int len = strlen(command);
	if(command[len-1] == '&'||command[len-2]){
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

void parseCommandInsideAsingleArray(char *command,char **arr){
	     while (*command != '\0') {
	          while (*command == ' ' || *command == '\t' || *command == '\n')
	               *command++ = '\0';
	          *arr++ = command;
	          while (*command != '\0' && *command != ' ' &&
	                 *command != '\t' && *command != '\n')
	        	  command++;
	     }*arr = '\0';
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


// the status value returned to the parent process.
void exitProcess(int status){
	printf("Thank you for using my terminal the terminal exit with status code: %d\n",status);
	exit(status);
};

void startShell(){


};

int reutrnStatusCode(char* const args[]){

return 1;
};

void printErrorMessages(int status[]){


};

void executeShellBuiltInCommands(char *command,char *args[]){


};


void execute(char **args){
	if(strcmp(commandsArr[0],"exit") == 0){
		exitProcess(0);
	}
	pid_t pid;
	int status;
	pid = fork();
	if(pid < 0){
	      printf("ERROR CAN'T FORK() \n");
	      exitProcess(errno);
	}else if(pid == 0){
	  /* Child process:
	   * When fork() returns 0, we are in
	   * the child process.
	   */

		int valid = execvp(commandsArr[0],args);
		if(valid < 0){executeShellBuiltInCommands(commandsArr[0],args);}
	}else{
	  /* When fork() returns a positive number, we are in the parent process
	   * (the fork return value is the PID of the newly created child process)
	   */
	    pid = wait(&status);
	}


};
void executeInBackground(char* const args[], const char* command){


};
void writeInLogFille(){


};
void childHandler(int sig){


};

