#include <stdio.h>
#include <math.h>

int main(){
	float sol=13;
	float a = 1, b= 0;
	float eps = pow(10,-4);;
	
	printf("Entrer l'intervalle choisi dans R: ");
	scanf("%f %f",&a,&b);
	
/// Methode de Newton ( tangente ) 
	sol = a * ( ( -(log(a)-1) )  + 1 ) ;

	while ( fabs(log(b)-1) > eps){
		sol = sol * ( ( -(log(sol)-1) )  + 1 ) ;
		b= sol;
		
		printf("x0 = %f\n",sol);
	}

	return 0;
}

