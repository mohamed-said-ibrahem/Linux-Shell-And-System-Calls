#include <stdbool.h>

#ifndef HELPER_METHODS_H_
#define HELPER_METHODS_H_

void exitProcess(int status);
void startShell();
void execute( char **args);
void executeShellBuiltInCommands(char *command,char *args[]);
void writeInLogFille(char *text);
void parseCommand(char *command);
char *removeWhiteSpaces(char *command);
int checkBackgroundExecution(char *command);
void parseCommandInsideAsingleArray(char *line, char **argv);
int cdCommand(char *pth);
char *trimWhiteSpaces(char *str);
void signalHandler(int sig_num);

#endif /* HELPER_METHODS_H_ */
