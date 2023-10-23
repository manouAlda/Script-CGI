#include <math.h>
#include <stdio.h>

int main(){
	
	float a = 1, b= 0, x=0 , y=0;
	float inter=0;
	float aire = 0;
	
	printf("Entrer l'intervalle choisi dans R: ");
	scanf("%f %f",&a,&b);
	
		inter = (b-a)/20;
/// Methode des trapèzes

	for (int i=0 ; i<= 20 ; i++){
		x= (a + (i* inter) ) ;
		y= (a + ((i+1)* inter) ) ;
		aire += ( ( ( log(x)-1) + (log( y) -1 ) ) * inter ) / 2 ;
		printf("\nx = %f   && y = %f    &&   aire = %f \n",x,y,aire);
	}
	printf("\nAire = %f \n",aire);
	
	return 0;
}
