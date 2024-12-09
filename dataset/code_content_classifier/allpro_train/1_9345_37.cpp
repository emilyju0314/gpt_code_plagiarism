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
	Info(int arg_value,int arg_watch_id){
		value = arg_value;
		watch_id = arg_watch_id;
	}
	bool operator<(const struct Info &arg) const{
		return value < arg.value;
	};

	int value,watch_id;
};

int calc(int hour,int minute,int second){
	return 3600*hour+60*minute+second;
}

int N;

void func(){

	int a,b,c,hour,minute,second,tmp_hour,tmp_minute,tmp_second;

	vector<Info> V;

	for(int loop = 0; loop < N; loop++){
		scanf("%d %d %d",&a,&b,&c);

		for(int i = 0; i < 6; i++){

			switch(i){
			case 0: //H:M:S
				hour = a;
				minute = b;
				second = c;
				break;
			case 1: //H:S:M
				hour = a;
				minute = c;
				second = b;
				break;
			case 2: //M:H:S
				hour = b;
				minute = a;
				second = c;
				break;
			case 3: //M:S:H
				hour = c;
				minute = a;
				second = b;
				break;
			case 4: //S:H:M
				hour = b;
				minute = c;
				second = a;
				break;
			case 5: //S:M:H
				hour = c;
				minute = b;
				second = a;
				break;
			}

			for(int diff = 0; diff <= 59; diff++){
				tmp_hour = (hour+diff)%60;
				tmp_minute = (minute+diff)%60;
				tmp_second =  (second+diff)%60;

				if(tmp_hour%5 != tmp_minute/12)continue;
				tmp_hour /= 5;
				V.push_back(Info(calc(tmp_hour,tmp_minute,tmp_second),loop));
			}
		}
	}

	sort(V.begin(),V.end());

	bool check[10],FLG;

	int minimum = BIG_NUM,ans_left,ans_right;

	for(int left = 0; left < V.size(); left++){
		for(int right = left; right < V.size();right++){
			for(int i = 0; i < N; i++)check[i] = false;
			for(int i = left; i <= right; i++)check[V[i].watch_id] = true;

			FLG = true;
			for(int i = 0; i < N; i++){
				if(!check[i]){
					FLG = false;
					break;
				}
			}

			if(FLG){
				if(minimum > V[right].value-V[left].value){
					minimum = V[right].value-V[left].value;
					ans_right = V[right].value;
					ans_left = V[left].value;
				}else if(minimum == V[right].value-V[left].value){
					if(ans_left > V[left].value){
						ans_right = V[right].value;
						ans_left = V[left].value;
					}
				}
			}
		}
	}

	printf("%02d:%02d:%02d %02d:%02d:%02d\n",ans_left/3600,(ans_left%3600)/60,(ans_left%3600)%60,ans_right/3600,(ans_right%3600)/60,(ans_right%3600)%60);
}

int main(){

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}