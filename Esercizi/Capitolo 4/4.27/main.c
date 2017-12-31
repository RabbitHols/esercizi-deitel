/** 
Trovare le terne pitagoriche fino a 500

a^2 + b^2 = c^2

**/

#include <stdio.h>
#include <math.h>

int potenza(int, int);

int main(){

	int	cnt_a = 0;
	int cnt_b = 0;
	int cnt_c = 0;
	int num_Iterazioni = 50;

	for(cnt_a = 1; cnt_a < num_Iterazioni; cnt_a++){
		for(cnt_b = 1; cnt_b < num_Iterazioni; cnt_b++){
			for(cnt_c = 1; cnt_c < num_Iterazioni; cnt_c++){
				if( potenza(cnt_a,2) + potenza(cnt_b,2) == potenza(cnt_c,2) ){
					printf("%d + %d = %d\n", cnt_a, cnt_b,cnt_c);
				}
			}
		}
	}

	return 0;
}

int potenza(int base, int esponente){

	int cnt = 0;
	int mlt = base;

	for(cnt; cnt < esponente - 1; cnt++){
		base = base * mlt;
	}

	return base;

}