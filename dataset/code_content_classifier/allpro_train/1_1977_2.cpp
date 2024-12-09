#include <iostream>
#include<stdio.h>
using namespace std;



int main(void){
	double a, b, c, d, e, f;
	double x, y;


	while (cin >> a >> b >> c >> d >> e >> f){

		 y = (c*d - a*f) / (b*d - a*e);
		 x = (c - b*y) / a;
	
		 printf("%.3lf ", x);
		 printf("%.3lf\n", y);

	
	}


	
	
	return 0;
}