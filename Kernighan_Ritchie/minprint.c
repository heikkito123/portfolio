/* A study of variadic argument functions */

#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>

void minprint(char *, ...);

int main(){
    unsigned int a = 55;
    char str[] = "this number is dec / hex / oct / addr ";
    void *ptr = &a;

    minprint("%s %d / 0x%X / Oct %o / %p\n", str, a, a, a, ptr);

}

void minprint(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    void *pval;
    int ival;
    double dval;
    unsigned int xval, oval;

    
    va_start(ap, fmt);

    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'x':
            case 'X':
                xval = va_arg(ap, unsigned int);
                printf("%X", xval);
                break;
            case 'o':
            case 'O':
                oval = va_arg(ap, unsigned int);
                printf("%o", oval);
                break;
            case 'p':
                pval = va_arg(ap, char *);
                printf("%p", (void *)pval);
                break;

            default:
                putchar(*p);
                break;
        }
    }
}
