/*
 Da C° a F°
 	: F° = (9/5)°C+32
 Da F° a C°
 	: C° = (5/9)x(°F - 32)
*/

#include <stdio.h>

double toFar(double temp);
double toCel(double temp);

void tabFar();

int main(){

	int gradi = 20.00;

	tabFar();

	return 0;
}

void tabFar(){
	
	double far = 0;

	for(int cnt = 0; cnt <= 100; cnt++){
		if(cnt % 5 == 0){
			puts("\n");
		}
		far = ( (double)cnt * 9.0/5.0 ) + 32;
		printf("\tC: %d\tF: %f  ", cnt, far);
	}
	puts("\n");

}

void tabCel(){
	
	double far = 0;

	for(int cnt = 0; cnt <= 100; cnt++){
		if(cnt % 5 == 0){
			puts("\n");
		}
		far = ( (double)cnt * 9.0/5.0 ) + 32;
		printf("\tC: %d\tF: %f  ", cnt, far);
	}
	puts("\n");

}
/*
double toCel(double temp){
	
	return ( (5.0/9.0)* (temp - 32));
	


}
*/
double toFar(double temp){

	return ( (temp * 9.0/5.0) + 32  );

}


