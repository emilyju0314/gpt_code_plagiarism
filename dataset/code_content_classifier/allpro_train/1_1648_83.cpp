#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
    
	printf("%lf\n", sqrt(pow(c - a, 2) + pow(d - b, 2)));
	return 0;
}

