#include "../helper/methods.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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

void parseCommand(char *command){

	char *token;
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
	printf("Thank you for using my terminal the terminal exit with status code: %d",status);
	exit(status);
};

void startShell(){


};

int reutrnStatusCode(char* const args[]){

return 1;
};
void printErrorMessages(int status[]){


};
void execute(bool waiting, char* const args[], const char* command){


};
void executeInBackground(char* const args[], const char* command){


};
void writeInLogFille(){


};
void childHandler(int sig){


};

