#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hex_to_char(char* tab){
	int val=0, decimal=0;
	int len = strlen(tab)-1;
	
	for (int i=0; tab[i]!='\0'; i++){
		if(tab[i]>= '0' && tab[i]<='9'){
			val = tab[i]-48;
		}else if(tab[i]>='a' && tab[i]<='f'){
			val = tab[i]-97+10;
		}else if(tab[i]>= 'A' && tab[i]<='F'){
			val = tab[i]-65+10;
		}else{
			return -1;
		}
		
		decimal += val* pow(16, len);
		len--;
	}
	
	return decimal;
}

char* withoutHex(char* tab) {
    char* new = malloc(strlen(tab) + 1);
    int i = 0, j = 0;
    char hex[3];
    char car;

    while (tab[i] != '\0') {
        if (tab[i] == '%' && tab[i + 1] != '\0' && tab[i + 2] != '\0') {
            hex[0] = tab[i + 1];
            hex[1] = tab[i + 2];
            hex[2] = '\0';

            car = hex_to_char(hex);

            if (car != -1) {
                new[j] = car;
                i += 3;
            } else {
                new[j] = tab[i];
                i++;
            }
        } else if (tab[i] == '+') {
            new[j] = ' ';
            i++;
        } else {
            new[j] = tab[i];
            i++;
        }
        j++;
    }
    new[j] = '\0';

    return new;
}

char* balise_html (char* balise, char* attribut, char* text, char* fin_balise){
    char* instruction = malloc (1000);

    if (strcmp(fin_balise,"")==0) {
        sprintf( instruction , "\n<%s %s>\n\t %s ",balise,attribut, text );
    }
    else if (strcmp(fin_balise,"")!=0){
        sprintf( instruction , "\n<%s %s>\n\t %s \t\n</%s>\n",balise,attribut, text, fin_balise );
    }
    return instruction;
}

void print_balise_html (char* balise, char* attribut, char* text, char* fin_balise){
    if (strcmp(fin_balise,"")==0){ 
        printf("\n<%s %s>\n\t %s ",balise,attribut, text );
    }
    else if (strcmp(fin_balise,"")!=0){
        printf("\n<%s %s>\n\t %s \t\n</%s>\n",balise,attribut, text, fin_balise );
    }
}

void classe (char* balise, char* text){
    printf("\n%s { \n %s }\n", balise, text);
}

void create_hosts (char* serverName){
    FILE* file = NULL;
    char* content = malloc(100);
    char* contenu = malloc(255);
    int test = 0;

    sprintf ( content,"127.0.0.1     %s", serverName);

    file = fopen ("/etc/hosts", "r");

    for (int i=0; feof(file)!=1; i++){
        fgets(contenu, 255, file);
        if (strstr(contenu, content)!=NULL)     test = 1;
    }
    fclose(file);
    file = fopen ("/etc/hosts", "a");
    if (test == 0)
        fprintf(file, "\n127.0.0.1     %s\n", serverName);

    fclose(file);
    free(content);      free(contenu);
}

char* create_conf (char* conf){
    FILE* file = NULL;
    char* instruction = malloc (500);
    char* directive = malloc (255);
    char* content = malloc(500);

    char* server = malloc(150);
    char* admin = malloc(150);
    char* root = malloc(150);
    char* site = malloc(100);
    char* command = malloc(255);
    char* error = malloc(20);
    char* access = malloc(30);
    char* fic = malloc(30);
    char* directory = malloc (255);

    char* allow = malloc(100);
    char* opt = malloc(255);
    char* add = malloc(100);
    char* req = malloc(255);

    char* contenu = malloc(500);
    char* name = malloc(20);

    sscanf(conf, "server=%[^&]&admin=%[^&]&error=%[^&]&access=%[^&]&document=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^\n]\n", server, admin, error, access, root, fic, directory);
    sscanf(server, "%*[^.].%[^.].%*[^\n]", site);
    strcat(site,".conf");

    sprintf(command, "sudo mkdir %s", root);
    //popen(command,"w");
    system(command);
    sprintf(command, "chmod o+rwx %s", root);
    popen(command,"w");
    sprintf(command, "cat %s", fic);
    popen(command,"w");

    if (strstr(directory,"Options")!=NULL){
        strcpy(opt,"Options");      strcat(opt," ");
        if(strstr(directory,"All")!=NULL && strstr(directory,"granted")==NULL) {
            strcat(opt,"All");       strcat(opt," ");
        }
        if(strstr(directory,"Indexes")!=NULL){
            strcat(opt,"+Indexes");       strcat(opt," ");
        }
        if(strstr(directory,"FollowSymLinks")!=NULL){
            strcat(opt,"+FollowSymLinks");       strcat(opt," ");
        }
        if(strstr(directory,"ExecCGI")!=NULL)    {
            strcat(opt,"+ExecCGI");       strcat(opt," ");
        }
        
    }   

    if (strstr(directory, "AllowOverride")!=NULL){
        strcpy(allow, "AllowOverride");  strcat(allow," ");
        if(strstr(directory, "allow=All")!=NULL){
            strcat(allow,"All");
        }
        if(strstr(directory, "allow=None")!=NULL){
            strcat(allow,"None");
        }
    } 

    if(strstr(directory, "AddHandler")!=NULL){
        strcat(add,"AddHandler cgi-script .cgi");
    }

    if(strstr(directory, "Require")!=NULL){
        strcpy(req,"Require all granted\n");
    }

    sprintf(contenu, "%s\n\t%s\n\t%s\n\t%s", opt, allow, add, req);

    directive = balise_html ("Directory", root, contenu, "Directory");

    sprintf(content, "ServerName %s\n\tServerAdmin %s\n\tDocumentRoot %s\n\t%s\n\tErrorLog ${APACHE_LOG_DIR}/%s\n\tCustomLog ${APACHE_LOG_DIR}/%s combined\n", server, admin, root, directive,error,access);

    instruction = balise_html ("VirtualHost", "*:80", content, "VirtualHost");

    file = fopen (site,"w");

    fprintf(file, "%s", instruction);

    fclose(file);

    sprintf(command, "cp %s /etc/apache2/sites-available/", site);
    
    system(command);

    create_hosts (server);

    strcpy(name, site) ; 

    free(contenu);
    free(directive);       free(instruction);             free(content);  
    free(server);  free(admin);  free(root);   free(site);  free(error);  free(access);      free(fic);      free(directory);    free(command);     
    free(allow);    free(req);      free(opt);    free(add);

    return name;
}
