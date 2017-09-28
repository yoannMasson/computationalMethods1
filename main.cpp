#include <iostream>
#include "vector.h"

using namespace std;
int sign(double x);

double f0(double x){
	return (1/2)*(sign(x)+1);
}

int sign(double x){
	if(x<0){
		return -1;
	}else if ( x == 0 ){
		return 0;
	}else {
		return 1;
	}
}


int main(){

cout << "Start\n";
double previousAnswer = 0;
Vector v  = Vector(100);
//The step is 0.4, s represent space
for(double s=-40; s<40 ; s = s+0.4){
	cout << f0(s);
} 
	
}


