#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var.h"

int main(){
	/// Declaration des donnees pour filter les 100 dernieres lignes où les sessions ouvertes ou fermees par un utilisateur dans le fichier /var/log/auth.log
	char* line= malloc(1000);
    char* month= malloc(4); 
    char* day= malloc(4);
    char* time= malloc(10); 
    char* session=malloc(10);
    char* login = malloc(10);
    char* hostname = malloc(100);
    char* service= malloc(100); 
    char* action = malloc(100);
    char* infos= malloc(100);
	
///Traitement
	// Print des balises HTML
	printf("Content-type:text/html\n\n");
	
	printf("<HTML>\n");
	printf("<HEAD>\n");
	printf("<title>Fichier log</title>\n");
	printf("</HEAD>\n");
	printf("<body bgcolor=\"white\">\n");
	
	//ouverture du fichier a filtrer 
	
	FILE* var = fopen("/var/log/auth.log", "r");
	
	if(var == NULL){
		printf("Erreur de l'ouverture du fichier /var/log/auth.log\n");
	}
	
	printf("<table border=\"1px\" width=\"100%%\" cellspacing=\"10\" cellpadding=\"10\" >\n");
    printf("    <caption align=\"top\"><h1><i>/var/log/auth.log</i></h1></caption>\n");
    printf("    <tr>\n");
    printf("       <td width=\"34%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>Time</b></font></td>\n");
    printf("       <td width=\"33%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>Opening/Closing </b></font></td>\n");
    printf("       <td width=\"33%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>User</b></font></td>\n");
    printf("    </tr>\n");
	
	int total = count_line(var);		// recuperation du nombre de ligne total du fichier /var/log/auth.Log
	int centaine = total -100;			// avoir le debut des 100 dernieres lignes
	
	for(int l=0;l<=total;l++){
		fgets(line,1000, var);
		
			strcpy (month ,strtok(line, " ") );       // Première partie est le mois 
            day = strtok(NULL, " ");
            time = strtok(NULL, " ");           
            
            hostname = strtok(NULL, " ");
            service = strtok(NULL, ":");    // Deuxième partie est le nom du service
            
            action = strtok(NULL, ":");     
            infos = strtok(NULL, ":");
            
            char* utilisateur = strtok(NULL, "\n"); 

            if(utilisateur !=NULL){
				
				if (strstr(utilisateur, "session") != NULL) {
					if(strstr(utilisateur, "opened")!=NULL){
						strcpy(session,"opened");
					
					}else if (strstr(utilisateur, "closed")!=NULL || strstr(utilisateur, "close")!=NULL){
						strcpy(session,"closed");
					}
					
					if (strstr(utilisateur, "for user ") !=NULL) {
						strcpy (login , strstr(utilisateur,"for user ") ) ;
					}
						
					if(l>=centaine){					
						printf("    <tr>\n");
						printf("       <td width=\"34%%\" bgcolor=\"#aed6dc\">%s %s %s</td>\n",month,day,time);
						printf("       <td width=\"33%%\" bgcolor=\"#ff9a8d\">session %s</td>\n",session);
						printf("       <td width=\"33%%\" bgcolor=\"#4a536b\">%s</td>\n",login);
						printf("    </tr>\n");		
					}		
				}			
			}			
	}
	
	printf(" </table> \n");	
	
	printf("</body>\n");
	printf("</HTML>\n\n");
	
	fclose(var);
	freedom (line,month,  day,  time,  session, login, hostname, service,  action,  infos); 
	
	return 0;
}
