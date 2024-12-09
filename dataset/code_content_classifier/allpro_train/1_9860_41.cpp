#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;



const int n = 6;
double p[n], q[n];

double getAns(double x)
{
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] * x + q[i] * (1. - x) == 0) continue;
		ans += max(p[i] * x, q[i] * (1. - x) ) / (p[i] * x + q[i] * (1. - x) ) * (p[i] * x + q[i] * (1. - x) );
	}
	eprintf("%.10lf\n", ans);
	return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &p[i] );
		p[i] /= 100;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &q[i] );
		q[i] /= 100;
	}
	double l = 0, r = 1;
	for (int it = 0; it < 200; it++)
	{
		double m1 = (2 * l + r) / 3;
		double m2 = (l + 2 * r) / 3;
	
		double a1 = getAns(m1);
		double a2 = getAns(m2);
		
		if (a1 < a2)
			r = m2;
		else
			l = m1;
	}
	eprintf("l = %.5lf\n", l);
	printf("%.10lf\n", getAns(l) );



	return 0;
}

