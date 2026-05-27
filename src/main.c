#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"

#define HELP_STR    "Experimental argument parsing program.\n" \
                    "\tAuthor: Will Otterbein\n" \
                    "\tArguments:\n" \
                    "\t\t--log-file | -lf\t\tPath to a log file to use with the program.\n" \
                    "\t\t--worker-threads | -wt\t\tNumber of threads that the program will use for heavy processing.\n"
#define LOG_FILE 0
#define WORKER_THREADS 1
#define USE_WIN_PATH 2

void println(char* str) {
    printf("%s\n", str);
}

/**
 * Experimental argument parsing.
 */
int main(int argc, char** argv) {
    exampleFunction();

    int nValArgs = 2;
    char* fArgs = (char*)calloc(nValArgs * sizeof(char), sizeof(char)); // found arguments (zerod character array)
    char** argVals = (char**)malloc(nValArgs * sizeof(char*)); // give me `n` char* slots in memory (1 for each arg literal value)

    // Simple Flag Parsing (start at 1, skip program name)
    for (int i = 1; i < argc; i++) {
        char* argStr = argv[i];
        
        if (argStr == NULL) {
            continue;
        }

        // Differentiate via the argname
        if ((strcmp(argStr, "--log-file") == 0 || strcmp(argStr, "-lf") == 0)
                && (*(fArgs + LOG_FILE) == 0)) {
            char* argValue = *(argv + i + 1);
            if (argValue == 0) {
                printf("%s is NULL.\n", argStr);
                argValue = NULL;
            }
            (*(argVals + LOG_FILE)) = argValue;
            (*(fArgs + LOG_FILE)) = 1;
            i++;
            continue;
        } else if ((strcmp(argStr, "--worker-threads") == 0 || strcmp(argStr, "-wt") == 0)
                && (*(fArgs + WORKER_THREADS) == 0)) {
            char* argValue = *(argv + i + 1);
            if (argValue == 0) {
                printf("%s is NULL.\n", argStr);
                argValue = NULL;
            }
            
            (*(argVals + WORKER_THREADS)) = argValue;
            (*(fArgs + WORKER_THREADS)) = 1;
            i++;
            continue;
        } else if ((strcmp(argStr, "--use-win-path") == 0 || strcmp(argStr, "-uwp") == 0)
                && (*(fArgs + USE_WIN_PATH) == 0)) {
            // Flag type, no value processing
            (*(argVals + USE_WIN_PATH)) = "1"; // TODO, WO: everything needs to be strings rn, need to come up w/ struct & abstract more of the impl
            (*(fArgs + USE_WIN_PATH)) = 1;
            continue;
        // Show the help string if that is requested 
        } else if (strcmp(argStr, "-h") == 0 || strcmp(argStr, "--help") == 0) {
            printf("%s\n", HELP_STR);
            exit(0); // show help string & then dip
        }
    }
    
    if (*(fArgs + LOG_FILE))
        printf("Log File Path: %s\n", *(argVals + LOG_FILE));
    if (*(fArgs + WORKER_THREADS))
        printf("Number of worker threads: %s\n", *(argVals + WORKER_THREADS));
    if (*(fArgs + USE_WIN_PATH))
        printf("Use winpath flag value: %s\n", *(argVals + USE_WIN_PATH));

    return 0;
}

