


/*
#include <iostream>
#include "../Helper/methods.h"

using namespace std;

int main(int argc, char* argv[]){
    cout<<argc<<endl;

    return 0;
}
*/

#include "../helper/methods.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//void  parse(char *line, char **argv)
//{
//     while (*line != '\0') {       /* if not the end of line ....... */
//          while (*line == ' ' || *line == '\t' || *line == '\n')
//               *line++ = '\0';     /* replace white spaces with 0    */
//          *argv++ = line;          /* save the argument position     */
//          while (*line != '\0' && *line != ' ' &&
//                 *line != '\t' && *line != '\n')
//               line++;             /* skip the argument until ...    */
//     }
//     *argv = '\0';                 /* mark the end of argument list  */
//}

//void  execute(char **argv)
//{
//     pid_t  pid;
//     int    status;
////
////     if ((pid = fork()) < 0) {     /* fork a child process           */
////    	 printf("*** ERROR: forking child process failed\n");
////    	 exit(1);
////     }
////     else if (pid == 0) {          /* for the child process:         */
////          if (execvp(*argv, argv) < 0) {     /* execute the command  */
////        	  printf("*** ERROR: exec failed\n");
////               exit(1);
////          }
////     }
////     else {                                  /* for the parent:      */
////          while (wait(&status) != pid);       /* wait for completion  */
////
////     }
//}

int main()
{


	while(1){
	char line[1024]={};
	char *commandLineArgs[1024]={};
	printf("SHELL->");
	scanf ("%[^\n]%*c", line);
	checkBackgroundExecution(line);
	parseCommand(line);
	parseCommandInsideAsingleArray(line,commandLineArgs);
	execute(commandLineArgs);
    printf("\n");

	}

	//EXAMPLE FOR SUDO OPERATION IT WILL WORK WITH IDES LIKE CODEBLOCKS BUT WILL NOT WORK WITH ECLIPSE
//	 char *argv[4];
//	 argv[0] = "sudo";
//	 argv[1] = "apt-get";
//	 argv[2] = "install";
//	 argv[3] = "git";
//	 argv[4] = NULL;
//	execvp("sudo",argv);


	//	parseCommand(line);
//


//	exitProcess(1);
//	startShell();



//     char  line[1024];             /* the input line                 */
//     char  *argv[64];              /* the command line argument      */

//
//	     char *cmd = "cp";
//	     char *argv[3];
//	     argv[0] = "cp";
//	     argv[1] = "/home/said/Desktop/r/Resume.pdf";
//	     argv[2] = "/home/said/Desktop/s";
//	     argv[3] = NULL;

	//
//	command = cp
//
//	args[0] = cp
//
//	args[1] = /home/john/r1.sav
//
//	args[2] = /home/john/anotherfolder
//	     execvp(cmd,argv); //This will run "ls -la" as if it were a c





     //
//     execvp(argv[], argv); //This will run "ls -la" as if it were a c

//
//     while (1) {                   /* repeat until done ....         */
//          scanf("%s",line);
//          parse(line, argv);       /*   parse the line               */
////
////          printf(argv[0]);
////          printf("\n");
////
////          printf(argv[1]);
////          printf("\n");
//
////          printf("%s", argv[1]);
////          printf("%s",argv[1]);
////          printf("%s",argv[2]);
//
//          if (strcmp(argv[0], "exit") == 0)  /* is it an "exit"?     */
//               exit(0);            /*   exit if it is                */
//          execute(argv);           /* otherwise, execute the command */
//     }
}

