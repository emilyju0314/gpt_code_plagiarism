#include<stdio.h>
int main(){
	double a,b;
	scanf("%lf%lf",&a,&b);
	if (a - b != 0){
		if (a - b < 0){
			printf("LESS\n");
			}
			else if(a - b > 0){
				printf("GREATER\n");
				}
		}
		else{
			printf("EQUAL\n");
			}
	return 0;
	}