#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int N;
int check_point[101];
double min_time[101][101];
double B,R,V,E,F;


double calcTime(int x){
	if(x >= R){

		return 1.0/(V-E*((double)x-R));
	}else{

		return 1.0/(V-F*(R-(double)x));
	}
}

void func(){

	check_point[0] = 0.0;
	for(int i = 1; i <= N; i++)scanf("%d",&check_point[i]);
	scanf("%lf",&B);
	scanf("%lf %lf %lf %lf",&R,&V,&E,&F);

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= i; k++)min_time[i][k] = DBL_MAX;
	}

	min_time[0][0] = 0;

	int x;
	double add_time;

	for(int point = 1; point <= N; point++){
		for(int changed_loc = 0; changed_loc <= point-1; changed_loc++){
			add_time = 0.0;
			for(int loc = check_point[point-1]; loc <= check_point[point]-1; loc++){
				x = loc - check_point[changed_loc];
				add_time += calcTime(x);
			}

			min_time[point][changed_loc] = min(min_time[point][changed_loc],min_time[point-1][changed_loc]+add_time);

			min_time[point][point] = min(min_time[point][point],min_time[point-1][changed_loc]+add_time+B);
		}
	}

	double ans = DBL_MAX;
	for(int i = 0; i < N; i++)ans = min(ans,min_time[N][i]);

	printf("%.10lf\n",ans);
}


int main(){

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}