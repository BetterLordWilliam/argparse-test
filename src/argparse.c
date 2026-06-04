#include <stdio.h>
#include <stdlib.h> 
#include "argparse.h"


void exampleFunction() {
    printf("this is an example function\n");
}

//
// initiat thoughts, probs should for allocation just return the
// pointer to PROGARGS instead of accepting a pointer & allocating / assigning
//


void ap_alloc(PROGARGS** args) {
    printf("I am not yet implemented.\n");
    *args = (PROGARGS*)malloc(sizeof(PROGARGS)); 
    (*args)->name = "I am the name";
}

void ap_free(PROGARGS** args) {
    printf("I am not yet implemented.\n");

    // This will be more complex, loop over the arguments & free each of them
    // Then free the memory used by PROGARGS type itself
    
}

//
// adding arguments of specific types
//

void ap_addStringArgument(PROGARGS* args, char* name) {
    printf("I am not implemented.\n");
}


void ap_addFlagArgument(PROGARGS* args, char* name) {
    printf("I am not implemented.\n");
}


void ap_addIntegerArgument(PROGARGS* args, char* name) {
    printf("I am not implemented.\n");
}

//
// the generic version of the method
//

void ap_addArgument(PROGARGS* args, char* name, enum ARGTYPE type) {
    printf("I am not implemented.\n");
}


