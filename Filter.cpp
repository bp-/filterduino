#include "Filter.h"

Filter::Filter() {
	G = 1;
	
	b0=1;
	b1=2;
	b2=1;
	
	a1=1;
	a2=1;
	
	u[0]=0; u[1]=0; u[2]=0;
	y[0]=0; y[1]=0; y[2]=0; 
}
  
float Filter::update(float u0) {
	u[2] = u[1];
	u[1] = u[0];
	u[0] = u0;
    
	y[2] = y[1];
	y[1] = y[0];
    
	y[0] = G*(b0*u[0] + b1*u[1] + b2*u[2]) - a1*y[1] - a2*y[2];
    
	return y[0];
}

