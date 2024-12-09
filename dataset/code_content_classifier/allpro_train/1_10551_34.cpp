#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	long a, b, x=0, count=0;
	double y=0;
	while( scanf(" %ld,%ld", &a, &b) != EOF ){
		x+=a*b;
		y+=b;
		++count;
	}
	printf("%ld\n%ld\n", x, lround(y/count));
	return 0;
}