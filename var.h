#ifndef VAR_H
#define VAR_H

#include <stdio.h>

char** allouer(int line,int cols);
int EstPoints(char* tab);
int count_line (FILE* f);
void freePasswd (char* contenu, char* user, char* mot, char* rep);
void freedom (char* line,char* month, char* day, char* time, char* session, char*login,char* hostname,char* service, char* action, char* infos);
#endif
