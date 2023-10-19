#ifndef LOG_H
#define LOG_H

#include <stdio.h>

typedef struct {
    char month[10];
    char date[20];
    char time[10];
    char host[100];
    char action[100];
    char infos[500];   
}Auth;

int count_line (FILE* f);
int EstPoints(char* tab);
void pheader();
void ptabeau (char* user,char* rep);
void ptraitement (FILE* file);
void freePasswd (char* contenu, char* user, char* mot, char* rep);
void foot();
void pfoot ();

char* separate (char* infos);
char* login_out (char* user);
char* month_gasy (char* month);
void row_cols (int i,Auth* lines);
void suivant (int debut, int fin, int i);
void affiche(Auth* lines,int debut,int fin,int i);
void recherche(char* user,Auth* lines,int i,int debut,int fin, int commence, int final);
void pagination(int total,int commence,int final);
void rien ();
void table();

void traitement_search (FILE* var,char* user,int search,int debut,int fin,int commence,int final);

void aheader(char* user);


#endif
