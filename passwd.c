#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var.h"

int main(){
	
/// Declaration des variables pour le tableau (utilisateur + repertoire personnel)
	char* contenu= malloc(255);	
	char* user = malloc(20);
    char* rep = malloc(20);
    char* mot = malloc(20);    
	int uid=13, i, j=0;
	int k=0;
	
	FILE* file ;
	file= fopen ("/etc/passwd","r");
	
	if (file == NULL){
		printf("Erreur d'ouverture du fichier /etc/passwd\n");
	}
	
/// Traitement 
	//Print des balises HTML
	printf("Content-Type: text/html\n\n");
	
	printf("<HTML>\n");
	printf("<HEAD>\n");
	printf("<title>Utilisateur</title>\n");
	printf("</HEAD>\n");
	printf("<body>\n");
	
	printf("<table border=\"1\" width=\"100%%\" cellspacing=\"10\" cellpadding=\"10\" >\n");
    printf("    <caption align=\"top\"><h1><i>User information</i></h1></caption>\n");
    printf("    <tr>\n");
    printf("       <td width=\"50%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>User</b></td>\n");
    printf("       <td width=\"50%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>Home directory</b></td>\n");
    printf("    </tr>\n");
		
	while(feof(file)!=1){
		fgets(contenu,255,file);
		k=EstPoints(contenu);
			
		mot = strtok(contenu,":");
		/// 1er champs
		if (mot == NULL)	continue;
		strcpy(user , mot);
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
		strcpy(rep ,mot);
	
		if(uid>=1000 && uid<5000){
			printf("    <tr>\n");
			printf("       <td width=\"50%%\" bgcolor=\"#E29E93\">%s</td>\n",user);
			printf("       <td width=\"50%%\" bgcolor=\"#E5EDF8\">%s</td>\n",rep);
			printf("    </tr>\n");
		}
		i++;
	}
	printf(" </table> \n");	
	
	
	printf("</body>\n");
	printf("</HTML>\n\n");
	
	fclose(file);
	freePasswd (contenu,user, mot,rep);

	return 0;
}
