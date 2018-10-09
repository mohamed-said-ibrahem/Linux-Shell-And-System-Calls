#include <stdbool.h>

#ifndef HELPER_METHODS_H_
#define HELPER_METHODS_H_


void exit();
void startShell();
int reutrnStatusCode(char* const args[]);
void printErrorMessages(int status[]);
void execute(bool waiting, char* const args[], const char* command);
void executeInBackground(char* const args[], const char* command);
void writeInLogFille();
void childHandler(int sig);
void parseCommand(char *command);
char *removeWhiteSpaces(char *command);
int checkBackgroundExecution(char *command);


#endif /* HELPER_METHODS_H_ */
