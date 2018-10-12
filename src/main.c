
#include "../helper/methods.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


int main()
{
	while(1)
	{
		char line[1024]={};
		char *commandLineArgs[1024]={};
		printf("SHELL--->\n");
		scanf ("%[^\n]%*c", line);
		char *newLine = trimWhiteSpaces(line);
		checkBackgroundExecution(newLine);
		parseCommand(newLine);
		parseCommandInsideAsingleArray(newLine,commandLineArgs);
		execute(commandLineArgs);
		printf("\n\n");
	}
}

