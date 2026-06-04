#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"

/**
 * Experimental argument parsing.
 */
int main(int argc, char** argv) {
    PROGARGS* pargs; ap_alloc(&pargs);

    printf("%a\n", pargs);
    printf("%s\n", pargs->name);

    ap_free(&pargs);
    
    return 0;
}


