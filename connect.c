#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "connect.h"

void oupps(){
    printf("<html>\n");
    printf("<head>\n");
    printf("    <title>Non connect&eacute;(e)</title>\n");
    printf("</head>\n");
    printf("<body bgcolor=\"#eff1f5\">\n");

    printf("<div style=\"background-color: black; padding: 1vw; text-align: right;\">\n");
    printf("        <font color=\"white\"><b>Fran&ccedil;ais(France)</b></font>\n");
    printf("    </div>\n");

    printf("       <div style=\"width: 100%%;  padding: 1.5vw; padding-left: 6vw; background: white; \">");
    printf("            <font color=\"blue\" size=\"6\"><b>/var/log/auth.log</b></font>\n");
    printf("       </div>");
    
    printf("<div align=\"center\" style=\"width: 38%%; height: 400px; background: papayawhip; margin-left: 25vw; padding: 3vw;\" >");
    printf(" <p><h2><i>Connectez-vous pour acceder &agrave; plus d'information concernant le fichier /var/log/auth.log! </i></h2></p>");
    printf("<br><br><br>");
    printf("<center><a href=\"http://www.site3.fr/programme/varLog.cgi?login\"><font size=\"13\">Connexion</font></a></center>\n");
    printf("</div>");   
    
  printf("</body>\n");
  printf("</html>");  
}

void inscrire(char* infos){
    printf("<html>\n");
    printf("<head>\n");
    printf("    <title>S'inscrire</title>\n");
    printf("</head>\n");
    printf("<body bgcolor=\"#eff1f5\">\n");

    printf("<div style=\"background-color: black; padding: 1vw; text-align: right;\">\n");
    printf("        <font color=\"white\"><b>Fran&ccedil;ais(France)</b></font>\n");
    printf("    </div>\n");

    printf("       <div style=\"width: 100%%;  padding: 1.5vw; padding-left: 6vw; background: white; \">");
    printf("            <font color=\"blue\" size=\"6\"><b>/var/log/auth.log</b></font>\n");
    printf("       </div>");
    
    printf("Si vous avez d&eacute;ja un compte, <a href=\"http://www.site3.fr/programme/varLog.cgi?login\" >Connexion</a>");
    printf("<div align=\"center\" style=\"width: 38%%; max-height: 700px; background: white; margin-top: 3vw; margin-left: 30vw;\" >");
    printf("<br><br><h1>Registration</h1><br>");
    printf("<form action=\"http://www.site3.fr/programme/authentification.cgi\" method=\"post\">");
    printf("    <b>Nom d'utilisateur</b><br><input type=\"text\" placeholder=\"Entrez le nom d'utilisateur\" name=\"utilisateur\" style=\"width: 33vw; height: 4vw;\" required/><br><br>");
    printf("      <b>Pseudo</b><br><input type=\"text\" placeholder=\"Pseudo\" name=\"pseudo\" style=\"width: 33vw; height: 4vw;\" required/><br><br>");
    printf("      <b>E-mail</b><br><input type=\"email\" placeholder=\"Votre email\" name=\"email\" style=\"width: 33vw; height: 4vw;\" required/><br><br>");
    printf("        <b>Mot de passe</b><br><input type=\"password\" name=\"mdp\" placeholder=\"********\" style=\"width: 33vw; height: 4vw; \" required/><br><br>");
    printf("          <b>Confirmer le mot de passe</b><br><input type=\"password\" name=\"passer\" placeholder=\"********\" style=\"width: 33vw; height: 4vw; \" required/><br><br>");
    printf("             <input type=\"submit\" value=\"S'inscrire\" style=\"width: 33vw; height: 4vw; background-color: red; color: white; font-size: 18px;\" /><br>");
    printf("</form>");
    printf("<p><font color=\"red\">%s</font></p>",infos);
    printf("<br><br>");
    printf("<br><br><br>");
    printf("</div>");   
    
  printf("</body>\n");
  printf("</html>"); 
 
}


void formulaire(char* infos){
    printf("<html>\n");
    printf("<head>\n");
    printf("    <title>Se connecter</title>\n");
    printf("</head>\n");
    printf("<body bgcolor=\"#eff1f5\">\n");

    printf("<div style=\"background-color: black; padding: 1vw; text-align: right;\">\n");
    printf("        <font color=\"white\"><b>Fran&ccedil;ais(France)</b></font>\n");
    printf("    </div>\n");

    printf("       <div style=\"width: 100%%;  padding: 1.5vw; padding-left: 6vw; background: white; \">");
    printf("            <font color=\"blue\" size=\"6\"><b>/var/log/auth.log</b></font>\n");
    printf("       </div>");
    
    printf("<div align=\"center\" style=\"width: 38%%; max-height: 500px; background: white; margin-top: 3vw; margin-left: 30vw;\" >");
    printf("<br><br><h1>Login</h1><br>");
    printf("<form action=\"http://www.site3.fr/programme/authentification.cgi\" method=\"post\">");
    printf("<input type=\"text\" placeholder=\"Adresse e-mail, nom de compte\" name=\"username\" style=\"width: 33vw; height: 4vw;\" required/><br><br>");
    printf("<input type=\"password\" placeholder=\"********\" name=\"password\" style=\"width: 33vw; height: 4vw;\" required/><br><br>");
    printf("<input type=\"submit\" value=\"Connexion\" style=\"width: 33vw; height: 4vw; background-color: red; color: white; font-size: 18px;\" /><br>");
    printf("</form>");
    printf("<br><br>");
    printf("<p><font color=\"red\">%s</font></p>",infos);
    printf("Vous n'avez pas de compte ? <a href=\"http://www.site3.fr/programme/varLog.cgi?inscrire\">Inscrivez-vous</a> ");
    
    printf("<br><br><br>");
    printf("</div>");   
    
  printf("</body>\n");
  printf("</html>");  
}

int hex_to_char(char* tab){
	int val=0, decimal=0;
	int len = strlen(tab)-1;
	
	for (int i=0; tab[i]!='\0'; i++){
		if(tab[i]>= '0' && tab[i]<='9'){
			val = tab[i]-48;
		}else if(tab[i]>'a' && tab[i]<'f'){
			val = tab[i]-97+10;
		}else if(tab[i]> 'A' && tab[i]<'F'){
			val = tab[i]-65+10;
		}else{
			return -1;
		}
		
		decimal += val* pow(16, len);
		len--;
	}
	
	return decimal;
}

char* withoutHex (char* tab){	
	char* new = malloc(strlen(tab)+1);	
	int i=0, j =0;
	char hex[4];
	char car;
	
	while(tab[i] != '\0'){
		if(tab[i]=='%' && tab[i+1] != '\0' && tab[i+2] != '\0'){
			snprintf(hex, sizeof(hex), "%c%c", tab[i+1], tab[i+2]);
			
			car = hex_to_char (hex);
			
			if(car != -1){
				new[j]=car;
				i+=3;
			} else{
				i += 3;
			}
		}
		else if(tab[i]=='%' &&  tab[i+1] != '\0' && tab[i+2] == '\0'){
			break;
		}
		else if(tab[i] == '+'){
			new[j]=' ';
			i+=1;
		}
		else{
			new[j] = tab[i];
			i++;
		}
		j++;
	}	
	new[j]='\0';
	
	return new;
}

int fichier_inscrit (char* infos){
  FILE* file = fopen("inscrit.csv","a+");
  FILE* f = fopen("connecte.csv","w");
  char nom[255], email[100], mdp[50], clone[50],pseudo[20],content[255];
  char user[100], id[50], mail[100];
  int confirmation=1;

  if(file==NULL)    printf("Erreur d'ouverture du fichier d'inscription\n");

  sscanf(infos,"%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^\n]\n", nom,pseudo, email, mdp, clone);

  for(int i=0; feof(file)!=1; i++){
    fgets(content, 255, file);
    sscanf(content, "%[^,],%[^,],%[^,],%*[^\n]\n",user, id, mail);
    if(strcmp(user,nom)==0 || strcmp(id,pseudo)==0 || strcmp(mail,email)==0 )
      confirmation=0;
  }

  if(strcmp(mdp,clone)!=0)  confirmation=0;
  else if (confirmation == 1) {
    fprintf(file, "%s,%s,%s,%s\n", nom, pseudo, email, mdp);
    fprintf(f, "%s,%s\n", pseudo, mdp);
  } 
    
  fclose(file);     fclose(f);

  return confirmation;
}

int fichier_connecte ( char* infos){
  FILE* file = fopen("connecte.csv","w");
  FILE* fichier = fopen("inscrit.csv","r+");
  char nom[255], mdp[50], name[100], email[100], passwd[50],pseudo[20];
  int connecte=0, verifier=0;
  char contenu[255];

  if(file==NULL)    printf("Erreur d'ouverture du fichier de connexion\n");
  if(fichier==NULL)    printf("Erreur d'ouverture du fichier d'inscription\n");

  sscanf(infos, "%[^&]&%*[^=]=%[^\n]\n", nom, mdp);

  for(int i=0; feof(fichier)!=1; i++){
    fgets(contenu, 255, fichier);
    sscanf(contenu, "%[^,],%[^,],%[^,],%[^\n]\n", name,pseudo, email, passwd);
    if( (strcmp(name,nom)==0 || strcmp(email,nom)==0 || strcmp(pseudo,nom)==0) &&  strcmp(passwd,mdp)==0){
      connecte=1;
        if(strcmp(email,nom)==0 || strcmp(name,nom)==0)			 
			strcpy(nom,pseudo);
      verifier=1;
    }
  }
  printf("<p><font color=\"blue\">username: %s = %s</font></p>",email,nom);
  if(connecte==1 && verifier==1){
    fprintf(file, "%s,%s\n", nom, mdp);
    connecte=2;
  }
  
  fclose(file);   fclose(fichier);
  return connecte;
}

char* user_id (char* username){
  FILE* fichier = fopen("inscrit.csv","r");
  char name[100], email[100],pseudo[20];
  char contenu[255];
  char* id = malloc(30);

  if(fichier==NULL)    printf("Erreur d'ouverture du fichier d'inscription\n");

  strcpy(id,username);
  for(int i=0; feof(fichier)!=1; i++){
    fgets(contenu, 255, fichier);
    sscanf(contenu, "%[^,],%[^,],%[^,],%*[^\n]\n", name,pseudo, email);
      if(strcmp(email,username)==0 || strcmp(name,username)==0)
        strcpy(id,pseudo);
  }

  fclose(fichier);
  return id;
}

void information (char* infos){
  FILE* file = fopen("inscrit.csv", "r");
  FILE* f= fopen("connecte.csv", "r");
  char contenu[255], connect[255], user[50], mdp[15], email[50], pseudo[20];

  fgets(connect, 255, f);
  sscanf(connect, "%[^,],%[^\n]\n", user, mdp);

  for(int i=0; feof(file)!=1; i++){
    fgets(contenu, 255, file);
    
    if(strstr(contenu,user)!=NULL && strstr(contenu,mdp)!=NULL ){
      sscanf(contenu, "%[^,],%[^,],%[^,],%[^,]", user,pseudo, email, mdp);
    }
  }

  printf("<html>\n");
    printf("<head>\n");
    printf("    <title>Information</title>\n");
    printf("</head>\n");
    printf("<body bgcolor=\"#eff1f5\">\n");

    printf("<div style=\"background-color: black; padding: 1vw; text-align: right;\">\n");
    printf("        <font color=\"white\"><b>Fran&ccedil;ais(France)</b></font>\n");
    printf("    </div>\n");

    printf("       <div style=\"width: 100%%;  padding: 1.5vw; padding-left: 6vw; background: white; \">");
    printf("            <font color=\"blue\" size=\"6\"><b>/var/log/auth.log</b></font>\n");
    printf("       </div>");
    
    printf("<div align=\"center\" style=\"width: 38%%; max-height: 650px; background: white; margin-top: 3vw; margin-left: 30vw;\" >");
    printf("<br><br><h1>User information</h1><br>");
    printf("<form action=\"http://www.site3.fr/programme/authentification.cgi\" method=\"post\">");
    printf("    <b>Nom d'utilisateur</b><br><input type=\"text\" value=\"%s\" name=\"name_modify\" style=\"width: 33vw; height: 4vw;\" /><br><br>",withoutHex(user));
    printf("      <b>Pseudo</b><br><input type=\"text\" name=\"pseudo\" value=\"%s\" style=\"width: 33vw; height: 4vw;\" ><br><br>",withoutHex(pseudo));
    printf("      <b>E-mail</b><br><input type=\"email\" value=\"%s\" name=\"email\" style=\"width: 33vw; height: 4vw;\" /><br><br>",withoutHex(email));
    printf("        <b>Mot de passe</b><br><input type=\"password\" name=\"mdp\" value=\"%s\" style=\"width: 33vw; height: 4vw; \" /><br><br>",withoutHex(mdp));
    printf("             <input type=\"submit\" value=\"Modifier\" style=\"width: 33vw; height: 4vw; background-color: beige; font-size: 18px;\" /><br>");
    printf("</form>"); 
    printf("<font color=\"red\">%s</font>",infos);
    printf("<br><br><br>");
    printf("</div>");   
    
  printf("</body>\n");
  printf("</html>"); 

  fclose(file);   fclose(f);
}


int modification (char* reply){
  FILE* file = fopen ("inscrit.csv", "r");
  FILE* exchange = fopen("copy.csv", "w+");
  FILE* connect=fopen("connecte.csv", "r");
  char signUp[255],content[255],contenu[255], nom[100], mdp[20], pseudo[20],email[50], name[100], passwd[20];
  int right=1;

  sscanf(reply, "%[&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^\n]\n", name, pseudo, email, passwd);

  fgets(signUp, 100, connect);
  sscanf(signUp, "%[^,],%[^\n]\n", nom, mdp);
  fclose(connect);
  
  for(int i=0; feof(file)!=1; i++){
    fgets(content, 255, file);
    if(strstr(content, nom)==NULL && strstr(content, mdp)==NULL)
      fprintf(exchange, "%s", content);
  }
  rewind(exchange);
 
  for(int i=0; feof(exchange)!=1; i++){
    fgets(contenu, 255, exchange);
    printf("<p><font color=\"purple\">content: %s</font></p>",contenu);
    if(strstr(content,pseudo)!=NULL || strstr(content,email)!=NULL)
      right=0;
  } /*
  if(right==1){
    FILE* connect=fopen("connecte.csv", "w");
    fprintf(exchange, "%s,%s,%s,%s\n", name, pseudo, email, passwd);
    fprintf(connect, "%s,%s\n", pseudo,passwd);
    fclose(connect);
  }
*/
  fclose(exchange);
  fclose(file); 
  
  return right;    
}

void deconnexion(){
  FILE* file = fopen("connecte.csv","w");
  if(file==NULL)  printf("Erreur d'ouverture du fichier de connexion\n");
  fclose(file);
}
