#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Info{
	double vw,pf,vf,th;
};

int N;
double pw;

Info* flower;

//?°´?????????water_amount??§????????¨????????±????????±???????????????????????????????¨????????????¢??°
double calc(double water_amount){
	double ret = water_amount*pw;

	for(int i = 0; i < N; i++){
		ret += max(0.0,flower[i].pf*((flower[i].th-water_amount*flower[i].vw)/flower[i].vf)); //??\??????????????£??§????????¨????????????
	}
	return ret;
}

//????????¢?´¢???????????¢??°(??????????????¢??°???????°????????±???????)
double thirds_search(double left,double right){

	if(fabs(right-left) < EPS){
		return calc((right+left)/2);
	}

	double mid1 = (2.0*left+right)/3.0;
	double mid2 = (1.0*left+2.0*right)/3.0;

	if(calc(mid1) > calc(mid2)){ //??§?????????????????´?????¨??????
		return thirds_search(mid1,right);
	}else{
		return thirds_search(left,mid2);
	}
}

void func(){
	scanf("%lf",&pw);

	for(int i = 0; i < N; i++){
		scanf("%lf %lf %lf %lf",&flower[i].vw,&flower[i].pf,&flower[i].vf,&flower[i].th);
	}

	printf("%.10lf\n",thirds_search(0.0,(double)BIG_NUM)); //?°´?????????0.0??\???
}

int main(){

	flower = (Info*)malloc(sizeof(Info)*100000);

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}