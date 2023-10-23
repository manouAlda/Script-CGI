#include "function.h"
#include <math.h>

float function (float x){
	return (log(x)-1);
}

float deriva ( float x, float x0 ) {
	return ( (x-x0) / (function(x)-function(x0) ) );
}	
