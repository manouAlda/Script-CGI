#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "function.h"

int main(){
	printf("Content-Type: text/html \n\n");
	
	float sol=13;
	float a = 1, b= 10;
	float eps = pow(10,-4);
	char* response = getenv("QUERY_STRING");
	char *interA = malloc(5);
	char *interB = malloc(5);
	
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Methode de Descarte</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	
	printf("<p>Entrer l'intervalle choisi dans R: </p>");
	printf("<form action=\"http://www.site3.fr/programme/descate.cgi\" method=\"get\">\n");
	printf(" A : <input type=\"number\" name =\"a\"><br>\n");
	printf(" B : <input type=\"number\" name =\"b\"><br>\n");
	printf(" <input type=\"submit\" value=\"submit\"><br>\n");
	printf("</form>\n");
	
	if(response != NULL){
		sscanf(response, "%*[^=]=%[^&]&%*[^=]=%[^\n]\n", interA,interB);
		a = atof(interA);		b = atof(interB);
	}
	
/// Methode de Descarte ( secante ) 
	if( interA!=NULL && interB!=NULL){
		sol =  b - ( function(b) * deriva(b,a) ) ;

		while ( fabs(log(b)-1) > eps){
			sol =  b - ( function(b) * deriva(b,a) ) ;
			b= sol;
			
			printf("<br>x0 = %f\n",sol);
		}
	}
	
	printf("</body>\n");
	printf("</html>\n");
	
	free(interA);
	free(interB);

	return 0;
}
