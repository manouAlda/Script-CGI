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
