#include <iostream>
#include "vector.h"


using namespace std;

int sign(double x){
	if(x<0){
		return -1;
	}else if ( x == 0 ){
		return 0;
	}else {
		return 1;
	}
}

double f0(double x){
	return 0.5*(sign(x)+1);
}



void upwindScheme(double deltaX,double deltaT,double resultArray[][100], double u){

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

void getAnalyticalSolution(double resultArray[][100], double deltaT){

	double t(0);
	for(int j = 0; j<5;j++){
		for(int i = 0; i<100; i++){
			resultArray[j][i] = 0.5*(sign((i*0.8)-40-t)+1);
		}
		t += deltaT;
	}
}

int main(){

	FILE* f = fopen("outputResult","w");
	double tableau[5][100];
	double analyticalSolution[5][100];
	cout << "Start\n";
	double previousAnswer = 0;
	double deltaX = 0.8;
	double deltaT = 0.7;
	int u = 1;
	//First entry is  time, second is space

	upwindScheme(deltaX,deltaT,tableau,u);
	getAnalyticalSolution(analyticalSolution,deltaT);
	
	cout << "Analytical solution\n";
	for(int i=0; i<5 ; i++){
		for(int j = 0; j<100; j++){
			fprintf(f,"%lf ,",analyticalSolution[i][j]);
			cout << analyticalSolution[i][j] << " ";
		}
		cout << "\n";
		fprintf(f,"\n");
	}
	fprintf(f,"\n");
	cout << "Computed solution\n";
	for(int i=0; i<5 ; i++){
		for(int j=0; j<100 ; j++){
			cout << tableau[i][j] << " ";
			fprintf(f,"%lf ,",tableau[i][j]);
		}
		fprintf(f,"\n");
		cout << "\n";
	}

	cout << "Error Matrix\n";
	for(int i=0; i<5 ; i++){
		for(int j=0; j<100 ; j++){
			cout << analyticalSolution[i][j] - tableau[i][j] << " ";
			fprintf(f,"%lf ,",analyticalSolution[i][j] - tableau[i][j]);
		}
		fprintf(f,"\n");
		cout << "\n";
	}
	cout << "End\n";

}
