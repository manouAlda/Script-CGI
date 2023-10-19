#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

int main(){	
	FILE* file ;

	//Print des balises HTML
	printf("Content-Type: text/html\n\n");
	
	pheader();
		
	ptraitement(file);
	
	foot();

	

	return 0;
}
