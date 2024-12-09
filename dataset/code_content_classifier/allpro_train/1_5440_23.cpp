#include<stdio.h>

int main(void){
	int warnings = 0;
	while(1){
		int std;
		double wgh,tll;
		double BMI = 0.0;

		if( EOF == scanf("%d,%lf,%lf", &std, &wgh, &tll) ) break;

		BMI = wgh / (tll * tll);

		if( BMI >= 25.0 ){
			printf("%d\n",std);
			warnings++;
		}
	}
	if(warnings == 0) printf("ツ該ツ督鳴づ按つオ\n");
	return 0;
}