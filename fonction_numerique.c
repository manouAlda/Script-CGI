#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "function.h"

int main(){

	printf("Content-Type: text/html\n\n");
	float a = 1, b= 0;
	char* response = getenv("QUERY_STRING");
	char *interA = malloc(5);
	char *interB = malloc(5);
	float* dicho = malloc(sizeof(float)*20);
	float* newton = malloc(sizeof(float)*20);
	float* descarte = malloc(sizeof(float)*20);
	float* rect = malloc(sizeof(float)*50);
	float* trap = malloc(sizeof(float)*50);
	int i=0, count=0;

	if(response != NULL){
		sscanf(response, "%*[^=]=%[^&]&%*[^=]=%[^\n]\n", interA,interB);
		a = atof(interA);		b = atof(interB);
	}

	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Fonction num&eacute;rique</title>\n");
	printf("<style>\n");
	printf(".entete{	display: flex;		justify-content: center;	}\n");
	printf(".fonction{	border-radius: 5px;		background-color: pink;		width: 70%%;	margin-left: 15%%;	}\n");
	printf(".intervalle{	border:thick ;	display: flex;	justify-content: space-around;	}\n");
	printf(".tableau{	background-color: rgb(245, 3, 75);	width: 80%%;	height: max-content;	border-radius: 10px;	margin-left: 10%%;	}\n");
	printf("</style>\n");
	printf("</head>\n");

	printf("<body>\n");
	printf("<div class=\"entete\">\n");
	printf("<h1><i><b><font color=\"red\">Fonction Num&eacute;rique</font></b></i></h1>\n");
	printf("</div>\n");
	printf("<hr><br>\n");

	printf("<div class=\"fonction\">\n");
	printf("<br><center><b><font color=\"white\" size=\"5\">log(x)-1</font></b></center><br>\n");
	printf("</div>\n");

	printf("<br><br><center>Entrer l'intervalle : </center><br>");
	printf("<div class=\"intervalle\">\n");
	printf("<form action=\"http://www.proud.com/cgi-bin/solution.cgi\" method=\"get\">\n");
	printf("<input type=\"number\" name=\"a\" placeholder=\"1\">	 <input type=\"number\" name=\"b\" placeholder=\"13\">\n");
	printf("<br><input type=\"submit\" value=\"submit\">\n");
	printf("</form>\n");
	printf("</div>\n");

	printf("<li>\n");
	printf("<ul>\n");
	printf("<h3><font color=\"coral\">->&nbsp;&nbsp;R&eacute;solution</font></h3>\n");
	printf("</ul>\n");
	printf("</li>\n");

	dicho = dichotomie(a,b);
	newton = newton_tangente(a,b);
	descarte = descarte_secante(a,b);

	if( strcmp(interA,"")!=0 && strcmp(interB,"")!=0){
		printf("<div class=\"tableau\">\n");
		printf("<table cellpading=\"15px\" width=\"100%%\" cellspacing=\"10px\">\n");
		printf("            <tr>\n");
		printf("                <td>\n");
		printf("<font color=\"yellow\">It&eacute;rations</font> <hr>\n");
		printf("                </td>\n");
		printf("                <td>\n");
		printf("<font color=\"yellow\">Methode de Dichotomie</font> <hr>\n");
		printf("                </td>\n");
		printf("                <td>\n");
		printf("<font color=\"yellow\">Methode de Newton </font><hr>\n");
		printf("                </td>\n");
		printf("                <td>\n");
		printf("<font color=\"yellow\">Methode de Descarte </font><hr>\n");
		printf("                </td>\n");
		printf("            </tr>\n");
		
		while ( dicho[count] != 0 ){
			printf("            <tr>\n");
			printf("                <td>\n");
			printf("%d <hr>\n",i);
			printf("                </td>\n");
			printf("                <td>\n");
			printf("%f<hr>\n",dicho[count]);
			printf("                </td>\n");
			printf("                <td>\n");
			printf("%f <hr>\n",newton[i]);
			printf("                </td>\n");
			printf("                <td>\n");
			printf("%f<hr>\n",descarte[i]);
			printf("                </td>\n");
			printf("            </tr>\n");
			i++;
			count++;
		}
		printf("        </table>\n");
		printf("</div>\n");
	}

	printf("<li>\n");
	printf("<ul>\n");
	printf("<h3><font color=\"coral\">->&nbsp;&nbsp;Int&eacute;grale</font></h3>\n");
	printf("</ul>\n");
	printf("</li>\n");

	rect = integral_rectangle(a,b);
	trap = integral_trapeze(a,b);

	if( strcmp(interA,"")!=0 && strcmp(interB,"")!=0){
		printf("<div class=\"tableau\">\n");
		printf("<table cellpading=\"15px\" width=\"100%%\" cellspacing=\"10px\">\n");
		printf("            <tr>\n");
		printf("                <td>\n");
		printf("<font color=\"yellow\">It&eacute;rations</font> <hr>\n");
		printf("                </td>\n");
		printf("                <td>\n");
		printf("<font color=\"yellow\">Methode de Rectangle</font> <hr>\n");
		printf("                </td>\n");
		printf("                <td>\n");
		printf("<font color=\"yellow\">Methode de Trap&egrave;ze </font><hr>\n");
		printf("                </td>\n");
		printf("            </tr>\n");
		i=0; count=0;
		while ( rect[count] != 0 ){
			printf("            <tr>\n");
			printf("                <td>\n");
			printf("%d <hr>\n",i);
			printf("                </td>\n");
			printf("                <td>\n");
			printf("%f<hr>\n",rect[count]);
			printf("                </td>\n");
			printf("                <td>\n");
			printf("%f <hr>\n",trap[i]);
			printf("                </td>\n");
			printf("            </tr>\n");
			i++;
			count++;
		}
		printf("        </table>\n");
		printf("</div>\n");
	}

	free(dicho);	free(newton); free(descarte);
		
	return 0;
}
