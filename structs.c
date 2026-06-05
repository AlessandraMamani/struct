#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "ritchie.h"
/*
int isspace(char c){
    return c == ' ' || c == '\n' || c == '\t';
    }

int isalpha(char c){
    return 'a' <= c && c <= 'z' ||
            'A' <= c && c <= 'Z';
    }

int isnum(char c){
    return '0' <= c && c <= '9';
    }

int isalnum(char c){
    return isalpha(c) || isnum(c);
    }
*/
int isalnum_(char c){
  return c == '_' || isalnum(c);
}

int getword (char *word, int lim) {

    int c;
    char *w = word;

    while (isspace(c = getch()));

    if(c != EOF) *w++ = c;

    if(!isalpha(c) && c != '\"'){ //if(!(isalpha(c) && c == '\"')){
        *w = 0;
        return c;
    }

    if(c == '\"')
        w--;
        while((c = getch()) != '\"'  && c != EOF){  
            if(c == '\\')
                c = getch();
            *w++ = c;
        }
        
        *w = 0;
        
        return word[0];

    for( ; --lim > 0; w++)
        if(!isalnum_(*w = getch())){  
            ungetch(*w);
            break;
        }
  
    *w = 0;
    return word[0];
}

