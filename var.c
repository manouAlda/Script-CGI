#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** allouer(int line,int cols){
	char **tab=NULL;
	tab=(char**)malloc(sizeof(char*)*line);
	for(int i=0;i<line;i++){
		*(tab+i)=(void*)calloc(cols,sizeof(char)*cols);
	}
	return tab;
}

int EstPoints(char* tab){
	int v=0;	
	for(int j=0;j<strlen(tab); j++)
			if(tab[j]==':' && tab[j+1]!=':')	v++;               							
	return v;
}

int count_line (FILE* f){
	f = fopen ("/var/log/auth.log","r");
	char* tab = malloc(300);
	int total=0;
	while(fgets(tab,300,f)){
		total++;
	}
	fclose(f);
	return total;
}

void freePasswd (char* contenu, char* user, char* mot, char* rep){
	free(contenu);
	free(user);
	free(rep);
	free(mot);
}

void freedom (char* line,char* month, char* day, char* time, char* session, char*login,char* hostname,char* service, char* action, char* infos){

	free(line);
	free(month);
	free(day);
	free(time);
	free(session);
	free(login);
	free(hostname);
	free(service);
	free(action);
	free(infos);

}

