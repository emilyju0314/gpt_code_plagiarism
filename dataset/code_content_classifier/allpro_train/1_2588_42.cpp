#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_LOOP = 86;
const int MAX_N = 100;
int n;
double x[MAX_N], y[MAX_N], v[MAX_N];

double dist(double x, double y, double x_, double y_){
	return sqrt((x - x_) * (x - x_) + (y - y_) * (y - y_));
}

double h(double px, double py){
	double res = 0;
	for(int i=0 ; i < n ; i++ ){
		double d = dist(px, py, x[i], y[i]);
		double t = d / v[i];
		res = max(res, t);
	}
	return res;
}

double g(double left, double right, double py){
	for(int i=0 ; i < MAX_LOOP ; i++ ){
		double mid1 = (left * 2 + right) / 3;
		double mid2 = (left + right * 2) / 3;
		if( h(mid1, py) < h(mid2, py) ){
			right = mid2;
		}else{
			left = mid1;
		}
	}
	return h((left + right) / 2, py);
}

double f(double left, double right){
	for(int i=0 ; i < MAX_LOOP ; i++ ){
		double mid1 = (left * 2 + right) / 3;
		double mid2 = (left + right * 2) / 3;
		if( g(0, 100, mid1) < g(0, 100, mid2) ){
			right = mid2;
		}else{
			left = mid1;
		}
	}
	return g(0, 100, (left + right) / 2);
}

int main(){
	while( scanf("%d", &n), n ){
		for(int i=0 ; i < n ; i++ ){
			scanf("%lf %lf %lf", &x[i], &y[i], &v[i]);
		}
		double ans = f(0,100);
		printf("%.8f\n", ans);
	}
}