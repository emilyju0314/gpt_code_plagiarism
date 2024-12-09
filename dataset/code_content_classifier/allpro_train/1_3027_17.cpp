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
	int start,end,S;
	bool check[361];
};


int main(){

	int N;
	scanf("%d",&N);

	Info info[N];

	for(int i = 0; i < N; i++){
		for(int day = 1; day <= 360; day++){
			info[i].check[day] = false;
		}
	}

	int month,day,length,value;

	for(int i = 0; i < N; i++){
		scanf("%d %d %d %d",&month,&day,&length,&value);
		info[i].start = 30*(month-1)+day;
		info[i].end = info[i].start+(length-1);

		for(int k = info[i].start; k <= info[i].end; k++){
			if(k > 360){
				info[i].check[k-360] = true;
			}else{
				info[i].check[k] = true;
			}
		}

		info[i].S = value;
	}

	int minimum = BIG_NUM,tmp,tmp_max,left_diff,right_diff,tmp_day;

	for(int day = 1; day <= 360; day++){
		tmp_max = 0;
		for(int i = 0; i < N; i++){

			if(info[i].check[day]){
				tmp = info[i].S;
			}else{

				for(tmp_day = day-1,left_diff = 1; ; left_diff++,tmp_day--){
					if(tmp_day <= 0){
						tmp_day = 360;
					}
					if(info[i].check[tmp_day]){
						break;
					}
				}

				for(tmp_day = day+1,right_diff = 1; ; right_diff++,tmp_day++){
					if(tmp_day > 360){
						tmp_day = 1;
					}
					if(info[i].check[tmp_day]){
						break;
					}
				}

				tmp = max(0,info[i].S-min(left_diff,right_diff));
			}

			tmp_max = max(tmp_max,tmp);
		}
		minimum = min(minimum,tmp_max);
	}

	printf("%d\n",minimum);

	return 0;
}