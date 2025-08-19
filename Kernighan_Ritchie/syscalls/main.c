/* A study into buffered syscall i/o with fopen and getc */
/*                                                       */
/* my_stdio.h for declarations and macros                */
/* my_stadio.c for definitions                           */
/* full implementation lacks buffer flushing!            */

#include "my_stdio.h"

int main(int argc, char *argv[]){
    FILE *fptr;
    int c;

    fptr = fopen(argv[1], "r");
    if (!fptr)
        return 1;
    
    while ((c = getc(fptr)) != EOF){
        putchar(c);
    }
    // flush buffer, TODO -> define own function instead of manual flush
    //
      if (stdout->ptr > stdout->base) {
        write(stdout->fd, stdout->base, stdout->ptr - stdout->base);
    }
    
    return 0;  return 0;
}

