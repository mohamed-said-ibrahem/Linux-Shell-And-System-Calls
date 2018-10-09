#include "../helper/methods.h"
#include <string.h>
#include <stdlib.h>

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
	   char *start;
	   indexA = 0;
	   indexB = 0;
	   indexC = 0;

	   length = strlen(command);

	   start = (char*) malloc (length+1);

	   if (start == NULL)
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
	      *(start+indexB) = *(command+indexA);
	      indexA++; indexB++;
	   }
	   *(start+indexB)= '\0';
	   if(*(start+indexC)== ' '){
		   while (*(start+indexC) != '\0') {
			   *(start+indexC) = *(start+indexC+1);
			   indexC++;
		   }
	   }
	   return start;

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

//void exit(bool waiting, char* const args[],char* command){
//
//
//};
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

