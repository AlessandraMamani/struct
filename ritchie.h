#ifndef RITCHIE_H
#define RITCHIE_H
#include <stdio.h>
#define BUFSIZE 100

/* Búfer compartido para las funciones de entrada */
char buf[BUFSIZE];  /* Búfer para ungetch */
int bufp = 0;       /* Próxima posición libre en buf */

//getch: Obtiene un carácter (posiblemente ya devuelto a la entrada)
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//ungetch: Devuelve un carácter a la entrada
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        fprintf(stderr, "ungetch: demasiados caracteres\n");
    } else {
        buf[bufp++] = c;
    }
}

#endif 

