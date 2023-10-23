#include <stdio.h>
#include <math.h>

int main(){
	float func = 0;
	float sol=13;
	float a = 1, b= 0;
	float eps = pow(10,-4);
	
	printf("Entrer l'intervalle choisi dans R: ");
	scanf("%f %f",&a,&b);

	sol = (a+b)/2 ;
	
	while ( fabs(b-a) > eps){
		func = (log(b)-1) * (log(sol)-1) ;
		
		if( func > 0 ){
			b = sol;
		}else if( func <= 0){
			a=sol;
		}	
		sol = (a+b)/ 2 ;
		
		printf("%f\n",sol);
	}

	return 0;
}

