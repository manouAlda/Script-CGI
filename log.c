#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log.h"
#include "connect.h"

int count_line (FILE* f){
	f = fopen ("/var/log/auth.log","r");
	int total=0;
	char contenu[300];
	while(fgets(contenu, sizeof(contenu), f) != NULL){
		if(strstr(contenu,"session opened")!=NULL || strstr(contenu,"session closed")!=NULL )
            total++;
	}

	fclose(f);
	return total;
}

/// Fichier /etc/passwd
int EstPoints(char* tab){
	int v=0;	
	for(int j=0;j<strlen(tab); j++)
			if(tab[j]==':' && tab[j+1]!=':')	v++;               							
	return v;
}

void pheader(){
	printf("<HTML>\n");
	printf("<HEAD>\n");
	printf("<title>Utilisateur</title>\n");
	printf("</HEAD>\n");
	printf("<body>\n");
	printf("<table border=\"1\"  width=\"100%%\"cellspacing=\"10\" cellpadding=\"10\" >\n");
    printf("    <caption align=\"top\"><h1><i><font color=\"red\">User information</font></i></h1></caption>\n");
    printf("    <tr>\n");
    printf("       <td width=\"50%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>User</b></td>\n");
    printf("       <td width=\"50%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>Home directory</b></td>\n");
    printf("    </tr>\n");
}

void ptabeau (char* user,char* rep){
	printf("    <tr>\n");
	printf("       <td width=\"50%%\" bgcolor=\"#E29E93\"><a href=\"http://www.site3.fr/programme/varLog.cgi?user=%s\">%s</a></td>\n",user, user);
	printf("       <td width=\"50%%\" bgcolor=\"#E5EDF8\">%s</td>\n",rep);
	printf("    </tr>\n");
}

void ptraitement (FILE* file){
	file= fopen ("/etc/passwd","r");
	char* contenu= malloc(255);	
	char* user = malloc(20);
    char* rep = malloc(20);
    char* mot = malloc(20);    
	int uid=13, i, j=0;
	int k=0;
	
	if (file == NULL){
		printf("Erreur d'ouverture du fichier /etc/passwd\n");
	}
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

		ptabeau(user,rep);	
		i++;
	}
	fclose(file);
	freePasswd (contenu,user, mot,rep);
}

void freePasswd (char* contenu, char* user, char* mot, char* rep){
	free(contenu);
	free(user);
	free(rep);
	free(mot);
}

void foot (){
    printf(" </table>  \n");
    printf("</body>\n");
	printf("<br><hr><br>\n");
	printf("</HTML>\n\n");
}

void table(){
    printf("<table border=\"1px\" width=\"100%%\" cellspacing=\"10\" cellpadding=\"10\" >\n");

    printf("    <caption align=\"top\"><h1><i><font color=\"red\"><a name=\"header\">/var/log/auth.log<a></font></i></caption>\n");

    printf("<tr>\n");
    printf("<a href=\"#footer\" >Aller en bas</a>\n");
    printf("</tr>\n");
   
    printf("    <tr>\n");
	printf("       <td width=\"03%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>Ligne</b></font></td>\n");
    printf("       <td width=\"32%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>Time</b></font></td>\n");
    printf("       <td width=\"32%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>Action</b></font></td>\n");
	printf("       <td width=\"32%%\" bgcolor=\"#ced7d8\"><font color=\"#000000\"><b>User</b></font></td>\n");
    printf("    </tr>\n");
}

/// Fichier /var/log/auth.cgi
void aheader(char* user){
	printf("<HTML>\n");
	printf("<HEAD>\n");
	printf("<title>Fichier log</title>\n"); 
	printf("</HEAD>\n");

	printf("<body bgcolor=\"white\">\n");

    printf(" <div style=\"width: 90%%;  display:flex; padding-left:70%%;\">\n");
    if(strcmp(user,"")==0)
        printf("         <a href=\"http://www.site3.fr/programme/varLog.cgi?login=-1\" style=\"color: black;\">Login</a>\n");
    else if(strcmp(user,"")!=0)
        printf("         <a href=\"http://www.site3.fr/programme/varLog.cgi?information\" style=\"color: black;\">Login</a>:<font color=\"indianred\">%s</font>\n",user);
    printf("         <span style=\" border-left: 2px solid #000; display: inline-block; height: 30px; margin: 0 20px;\"></span>");
    printf("         <a href=\"http://www.site3.fr/programme/varLog.cgi?deconnexion\" style=\"color: black;\">Se d&eacute;connecter</a>");
    printf(" </div>\n");

    printf("<hr>\n");

    printf("<div style=\"display: flex; justify-content: space-between;\">\n");
    printf("<div style=\"display: flex;\">\n");      
    printf("<button><a href=\"http://www.site3.fr/programme/varLog.cgi?suivant=-1\">All</a></button>&nbsp;&nbsp;&nbsp;\n");
    printf("<button><a href=\"http://www.site3.fr/programme/varLog.cgi?hundred=-1\">Last Hundred</a></button>&nbsp;&nbsp;&nbsp;\n");
    printf("</div>\n");

	printf("<div style=\"display: flex;\">\n");
    printf("      <form action=\"http://www.site3.fr/programme/varLog.cgi\" method=\"get\">\n");
    printf("            Search user: <input type=\"search\" name=\"user\" placeholder=\"mit\"/> \n");
	printf("      </form>\n");
    printf("</div>");

    printf("</div>");

	table();
}

void pagination(int total,int commence,int final){
	int count =0;
	count = (total+9) / 10;
	if(commence<1) commence=1;
    if(final>count) final=count;

    printf("    <tr>\n");
	printf("    <td colspan=\"5\" >\n");

    printf("<div style=\"display: flex; justify-content: space-between; \">\n");

    printf("<form action=\"http://www.site3.fr/programme/varLog.cgi\" method=\"get\">\n");
		for (int i=commence; i<= final ; i++){
			if(i==commence && i>1)
				printf("           <button name=\"plage_avant\" value=\"%d\"> << </button>\n",i);
			printf("           <button name=\"page\" value=\"%d\">%d</button>\n",i,i);

			if(i==final)
				printf("           <button name=\"plage_apres\" value=\"%d\"> >> </button>\n",i);
		}
    printf("    </form>\n");
    printf("<form action=\"http://www.site3.fr/programme/varLog.cgi\" method=\"get\">\n");

    printf("Search page n&deg;<input type=\"number\" name=\"page\"/>");
    printf("    </form>\n");
    printf("</div>\n");
    
	printf("    </td>\n");
	printf("    </tr>\n");
	printf(" </table>  \n");
}

void pfoot (){
    printf("<div style=\"display: flex; justify-content: space-between; \">\n");
    printf("<a href=\"#header\">&nbsp;&nbsp;Revenir en haut</a>");
    printf("<a name=\"footer\"><b><font size=\"1\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/var/log/auth.log</font></b></a>");
    printf("</div>\n");		

	printf("</body>\n");
	printf("<br><hr><br>\n");
	printf("</HTML>\n\n");
}

char* separate (char* infos){
    char* action = malloc(100);
    int j=0;
    for(int i=0;i<strlen(infos); i++){
        if( (infos[i]=='f' && infos[i+1]=='o' && infos[i+2]=='r' && infos[i+3]==' ' && infos[i+4]=='u') ||  (infos[i]=='o' && infos[i+1]=='f' && infos[i+2]==' ' && infos[i+3]=='u') ){
            break;
        }
        action[j]=infos[i];
        j++;
    }
    return action;
}

char* login_out (char* user){
    char* tmp;
    int j=0;
    for(int i=5; i<strlen(user) ; i++){
		if( ( user[i]=='b' && user[i+1]=='y' ) || (user[i]=='.'&& user[i+1]=='\0'))
			break;
        if(user[i]=='(' && user[i+1]=='u' && user[i+2]=='i' && user[i+3]=='d' && user[i+4]=='='){
            break;
        }
		tmp[j]=user[i];
		j++;
	}
	tmp[j]='\0';	
    return tmp;
}

char* month_gasy (char* month){
	char* monat= malloc(20);
	char mois[12][5]={ "Jan","Fev","Mar","Avr","Mey","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	char volana[12][20]={ "Janoary","Febroary","Martsa","Aprily","May","Jona","Jolay","Aogositra","Septambra","Oktobra","Novambra","Desambra" };
	
	for(int i=0;i<12;i++){
		if(strcmp(month,mois[i])==0){
			strcpy(monat,volana[i]);
		}
	}
	return monat;
}

char* andro_gasy (int jour,char* month,int annee){
	/// on commence a l'année 1901 qui a commencee le mardi 1 Janvier 1901
	char andro[7][15]={ "Alahady", "Alatsinainy", "Talata", "Alarobia", "Alakamisy", "Zoma", "Sabotsy"};
	char mois[12][5]={ "Jan","Fev","Mar","Avr","Mey","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	char isa[12][3]={"31", "28", "31","30","31","30","31","31","30","31","30","31"};
	char* tag  = malloc(15);
	int day=2;
	int annee_ecoulee = 0;
	int jour_bissextil=0;
	int jour_ecoule =0;
	
	annee_ecoulee = annee -1901 ;
	jour_bissextil = annee_ecoulee / 4;
	if(annee%400==0){	
		strcpy(isa[1],"29");
	}
	for(int i=0;i<12;i++){
		if(strcmp(month,mois[i])==0){
			break;
		}
		jour_ecoule += atoi(isa[i]);
	}
	
	day = jour + jour_ecoule + jour_bissextil + annee_ecoulee + 1 ;
	day = day % 7;
	strcpy(tag, andro[day]);
	
	return tag;
}

void row_cols (int i,Auth* lines){
    char volana[20];
    char andro[20];
    char tmp[255];
    char login[100];
  
        printf("    <tr>\n");
        printf("       <td width=\"04%%\" bgcolor=\"#aed6dc\">%d</td>\n",i);

        strcpy(andro, andro_gasy(atoi(lines[i].date), lines[i].month, 2023) );
        strcpy( volana, month_gasy(lines[i].month) ) ; 

        printf("       <td width=\"32%%\" bgcolor=\"#aed6dc\">%s faha %s %s %s</td>\n", andro,lines[i].date,volana,lines[i].time);
        
        if(strstr (lines[i].infos,"user ") != NULL ){
            strcpy(tmp,separate(lines[i].infos));

            if( strstr(tmp,"session opened")!=NULL || strstr(tmp,"session closed")!=NULL ){
                if(strstr(tmp,"session opened")){
                    printf("       <td width=\"32%%\" bgcolor=\"#ff9a8d\"><b><i><font color=\"green\">%s</font></i></b></td>\n",strstr(tmp,"session opened") );
                } else if (strstr(tmp,"session closed")){
                    printf("       <td width=\"32%%\" bgcolor=\"#ff9a8d\"><b><i><font color=\"red\">%s</font></i></b></td>\n",strstr(tmp,"session closed") );
                }
	        }

            strcpy(login,strstr (lines[i].infos,"user "));
            strcpy( login , login_out(login) );
            if(strstr (lines[i].infos,"(uid=")!=NULL)
                printf("       <td width=\"32%%\" bgcolor=\"#4a536b\"><a href=\"http://www.site3.fr/programme/varLog.cgi?user=%s\"><font color=\"orange\">%s</font></a>%s </td>\n",login,login, strstr (lines[i].infos,"(uid="));
            else{
                printf("       <td width=\"32%%\" bgcolor=\"#4a536b\"><a href=\"http://www.site3.fr/programme/varLog.cgi?user=%s\"><font color=\"orange\">%s</font></a></td>\n",login,login);
            }
        }else{
            printf("       <td width=\"32%%\" bgcolor=\"#ff9a8d\"></td>\n");
            printf("       <td width=\"32%%\" bgcolor=\"#4a536b\"></td>\n");
        }
        printf("    </tr>\n");	
}

void suivant (int debut, int fin, int i){
    printf("<tr>\n");
    printf("    <td colspan=\"4\">\n");
    printf("        <div style=\"display: flex; justify-content: space-between; \">");
    if(debut==1)
        printf("            <div style=\"display: none;\"><a href=\"http://www.site3.fr/programme/varLog.cgi?avant=%d\"\"> Previous </a></div>\n",fin);
    else
        printf("            <div ><a href=\"http://www.site3.fr/programme/varLog.cgi?avant=%d\"\"> Previous </a></div>\n",fin);
    printf("            <div>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~</div>\n");
    if(fin>= i)
        printf("            <div style=\"display: none;\"><a href=\"http://www.site3.fr/programme/varLog.cgi?suivant=%d\"\"> Next </a></div>\n",fin);
    else
        printf("            <div><a href=\"http://www.site3.fr/programme/varLog.cgi?suivant=%d\"\"> Next </a></div>\n",fin);
    printf("        <div>");
    printf("    </td>\n");
    printf("</tr>\n");
}

void affiche(Auth* lines,int debut,int fin, int i){
    for(int j=1; j<=fin; j++ ){
        if(j>=debut && j<= fin){
            row_cols(j,lines);
        }
        else if(j>fin){
            break;
        }
    }
    suivant(debut, fin, i );
}

void rien (){
    printf("    <tr>\n");
        printf("       <td width=\"04%%\" bgcolor=\"#EEEEEE\">Nothing</td>\n");
        printf("       <td width=\"32%%\" bgcolor=\"#EEEEEE\">Nothing</td>\n");	
        printf("       <td width=\"32%%\" bgcolor=\"#EEEEEE\">Nothing</td>\n");
        printf("       <td width=\"32%%\" bgcolor=\"#EEEEEE\">Nothing</td>\n");       
    printf("    </tr>\n");	
}

void recherche(char* user,Auth* lines,int i,int debut,int fin, int commence, int final){
    //char* infos;
    int misy=0;
    int count =0;
    
	if(strcmp(user,"")==0)
		rien();
	else{
		for(int j=0; j<i; j++){
			if(j>=debut && j<=fin){            
				row_cols(j,lines);
				misy++;    
			}  
		}
	}
    if(misy==0)
        rien();
    
    printf("<tr>\n");
    printf("    <td colspan=\"4\">\n");
    printf("        <div style=\"display: flex; justify-content: space-between; \">");
    if(debut==1)
        printf("            <div style=\"display: none;\"><a href=\"http://www.site3.fr/programme/varLog.cgi?user=%s&avant_user=%d\"\"> Previous </a></div>\n",user,fin);
    else
        printf("            <div ><a href=\"http://www.site3.fr/programme/varLog.cgi?user=%s&avant_user=%d\"\"> Previous </a></div>\n",user,fin);
    printf("            <div>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~</div>\n");
    if(fin>= i)
        printf("            <div style=\"display: none;\"><a href=\"http://www.site3.fr/programme/varLog.cgi?user=%s&suivant_user=%d\"\"> Next </a></div>\n",user,fin);
    else
        printf("            <div><a href=\"http://www.site3.fr/programme/varLog.cgi?user=%s&suivant_user=%d\"\"> Next </a></div>\n",user,fin);
    printf("        <div>");
    printf("    </td>\n");
    printf("</tr>\n");
  
	count = (i+9) / 10;

	if(commence<1) commence=1;
    if(final>count) final=count;

    printf("    <tr>\n");
	printf("    <td colspan=\"5\" >\n");

    printf("<div style=\"display: flex; justify-content: space-between; \">\n");

    printf("<form action=\"http://www.site3.fr/programme/varLog.cgi\" method=\"get\">\n");
	for (int i=commence; i<= final ; i++){
        if(i==commence)
            if(i>1){
                printf("           <button name=\"user %s plage_avant\" value=\"%d\"> << </button>\n",user,i);  }
		printf("           <button name=\"user %s page\" value=\"%d\">%d</button>\n",user,i,i);

        if(i==final && i<count)
            printf("           <button name=\"user %s plage_apres\" value=\"%d\"> >> </button>\n",user,i);
	}
    printf("    </form>\n");
    printf("<form action=\"http://www.site3.fr/programme/varLog.cgi\" method=\"get\">\n");

    printf("Search page n&deg;<input type=\"number\" name=\"user %s page\"/>",user);
    printf("    </form>\n");
    printf("</div>\n");
    
	printf("    </td>\n");
	printf("    </tr>\n");

	printf(" </table>  \n");
}

void traitement_search (FILE* var,char* user,int search,int debut,int fin,int commence,int final){
    int nbr = count_line(var);
    int i = 0;
    char contenu[nbr+1];
    char* infos;
    Auth* lines = (Auth*)malloc(nbr * sizeof(Auth));

    var = fopen("/var/log/auth.log", "r");
    if (var == NULL) {
        printf("Erreur d'ouverture du fichier");
    }

    while (fgets(contenu, sizeof(contenu), var) != NULL) {
        // Analysez la ligne pour extraire les donnees
        if(strstr(contenu,"session opened")!=NULL || strstr(contenu,"session closed")!=NULL ){
            if(search==1){
                infos = strstr(contenu ,"user ");  
                if( strstr(infos,user)!=NULL ){
                    sscanf(contenu, "%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^\n]\n" ,lines[i].month, lines[i].date, lines[i].time, lines[i].host, lines[i].action,lines[i].infos);
                    i++;
                }
            } else if (search==0){
                sscanf(contenu, "%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^\n]\n" ,lines[i].month, lines[i].date, lines[i].time, lines[i].host, lines[i].action,lines[i].infos);
                i++;
            }
        }
    }
    
    if(search==0){
        affiche (lines,debut,fin,i);
        pagination(i,commence, final);
    }
    else if(search==1){
        recherche(user,lines,i,debut,fin,commence,final);
    }

    // Fermez le fichier
    fclose(var);
    free(lines);
}
