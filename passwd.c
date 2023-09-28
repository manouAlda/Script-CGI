#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var.h"

int main(){
	char* contenu= malloc(255);
	
	char* user = malloc(20);
    char* rep = malloc(20);
    char* mot = malloc(20);    
	int uid=13, i, j=0;
	int k=0;
	
	FILE* file ;
	file= fopen ("/etc/passwd","r");
	
	if (file == NULL){
		printf("Erreur d'ouverture du fichier\n");
	}
	
	printf("Content-Type: text/html\n\n");
	
	printf("<HTML>\n");
	printf("<HEAD>\n");
	printf("<title>Utilisateur</title>\n");
	printf("</HEAD>\n");
	printf("<body bgcolor=\"pink\">\n");
	
	printf("<table border=\"1\" width=\"100%%\" cellspacing=\"10\" cellpadding=\"10\" >\n");
    printf("    <caption align=\"top\"><h1>User information</h1></caption>\n");
    printf("    <tr>\n");
    printf("       <td width=\"50%%\" bgcolor=\"#000000\"><font color=\"#FFFFFF\">User</font></td>\n");
    printf("       <td width=\"50%%\" bgcolor=\"#000000\"><font color=\"#FFFFFF\">Home directory</font></td>\n");
    printf("    </tr>\n");
		
	while(feof(file)!=1){
		fgets(contenu,255,file);
		k=EstPoints(contenu);
			
		mot = strtok(contenu,":");
		/// 1er champs
		if (mot == NULL)	continue;
		user = mot;
		/// 2em champs
		mot = strtok(NULL,":");
		if (mot == NULL)	continue;
		/// 3em champs
		mot = strtok(NULL,":");
		if (mot == NULL)	continue;
		uid = atoi(mot);
		/// 4em,5em et 6em champs en boucle 
		int fin ;
		if(k==5)	fin=2;
		else if(k==6)	fin=3;
		for (j=0; j<fin;j++){
			mot = strtok(NULL,":");
			if (mot == NULL)	continue;
		}	
		rep = mot;
	
		if(uid>=1000 && uid<5000){
			printf("    <tr>\n");
			printf("       <td width=\"50%%\">%s</td>\n",user);
			printf("       <td width=\"50%%\">%s</td>\n",rep);
			printf("    </tr>\n");
		}
		i++;
	}
	printf(" </table> \n");	
	
	
	printf("</body>\n");
	printf("</HTML>\n\n");
	
	fclose(file);
	free(contenu); 

	return 0;
}
