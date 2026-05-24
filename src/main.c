#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * # Argument Parser Utility
 * Ideas / implementation notes for the argument parser utility.
 *
 * ## Specifications
 *
 * This program (rather the argument parsing implementation) should do the following things:
 *
 * - Add arguments of types to be parsed in any C program.
 *      - types
 *          - switch (bool), yes or no (1 | 0) flags -- no value
 *          - string or char*, most likely path
 *          - path, raw type is char* but validate location on system w/ syscall
 *          - integer, an integer value
 *              - integers with certain valid values (enum types)
 *          - ... (not really sure what other types of arguments are useful in a program)
 *
 * ## Imagined use
 *
 * 1. The programmer includes this project in their entry file, & invokes from main.
 * 2. The programmer adds the desired arguments to a data strcture which will track the type & of course number of arguments to expect.
 *
 * ```c
 * addFlagArg(argDataStruct, "--my-flag-name", "-s", "this is the arguments help message / description");
 * addStringArg(argDataStruct, "--my-string-argument-name", "-m", "this is the arguments help message / description")
 * addIntegerArg(ardDataStruct, "--my-")
 * ```
 *
 * 3. The programmer then invokes a function that consumes their arugment configuration & this will return another structure containing the values of their arguments, or any errors that occured during the parsing of arguments.
 *
 * ```c
 * parseArguments(argDataStruct, argc, argv);
 * ```
 *
 * 4. Without the programmer explicitly needing to define this, there is a `-h | --help` parameter, which collects the defined help descriptions & shows a message w/ the help values to stdout.
 */

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
            continue; // no need to perform further increment because value is defined automatically
        } else if (strcmp(argStr, "-h") == 0) {
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

