#ifndef _argparse
#define _argparse

enum ARGTYPE {
    string,
    flag,
    integer
};

typedef struct {
    char* name;
    enum ARGTYPE type;
} ARG;

typedef struct {
    char* name; // debug property
    ARG **args;
} PROGARGS;


void exampleFunction();

/*
 * Will allocate memory needed for an instance of the program arguments struct.
 * */
void ap_alloc(PROGARGS** args);
void ap_free(PROGARGS** args);


void ap_addStringArgument(PROGARGS* args, char* name);
void ap_addFlagArgument(PROGARGS* args, char* name);
void ap_addIntegerArgument(PROGARGS* args, char* name);


void ap_addArgument(PROGARGS* args, char* name, enum ARGTYPE type);


#endif


