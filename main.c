#include <stdio.h>
#include "structs.h"
#define BUFF_SIZE 256

int main(){
    char buffer[BUFF_SIZE];

    while(getword(buffer, BUFF_SIZE) != EOF)
        printf("%s\n", buffer);
    
    return 0;
    }
