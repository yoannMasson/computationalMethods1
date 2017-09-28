#include <iostream>


using namespace std;
int sign(double x);

double f0(double x){
	return 0.5*(sign(x)+1);
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

double upwindScheme(double deltaX,double deltaT,double u){

	double resultArray[5][100];

	for(int i=0; i<100 ; i++){
		resultArray[0][i] = f0(-40+deltaX*i);	
	} 

	for(int i=1; i<5 ; i++){
		resultArray[i][0] = 0;
		resultArray[i][99] = 1;
		for(int j=1; j<99 ; j++){
			resultArray[i][j] = -u*deltaT*((resultArray[i-1][j]-resultArray[i-1][j-1])/deltaX)+ resultArray[i-1][j];
		}
		cout << "\n";
	}
}


int main(){

	cout << "Start\n";
	double previousAnswer = 0;
	double deltaX = 0.8;
	double deltaT = 0.001;
	int u = 1;
	//First entry is  time, second is space
	double[][] resultArray = upwindScheme(deltaX,deltaT,u);

	//The step is 0.8
	for(int i=0; i<5 ; i++){
		for(int j=0; j<100 ; j++){
			cout << resultArray[i][j] << " ";
		}
		cout << "\n";
	} 
	cout << "End\n";
	
}


