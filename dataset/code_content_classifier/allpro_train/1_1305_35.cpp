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

	Info(int arg_time,int arg_loc){
		time = arg_time;
		loc = arg_loc;
	}
	bool operator<(const struct Info &arg) const{
		return time < arg.time;
	};

	int time,loc;
};

int main() {

	int N,Limit;

	scanf("%d %d",&N,&Limit);

	Info* info = (Info*)malloc(sizeof(Info)*N);

	for(int i = 0; i < N; i++){
		scanf("%d %d",&info[i].time,&info[i].loc);
	}

	sort(info,info+N);

	ll ans = 0;
	int pre_time = 0,pre_loc = 1;
	vector<int> Elevator;

	for(int i = 0; i < N; i++){
		if(info[i].time-pre_time < abs(info[i].loc-pre_loc)){
			printf("-1\n");
			return 0;
		}

		if(info[i].time-pre_time >= (pre_loc-1)+(info[i].loc-1)){
			for(int k = 0; k < Elevator.size(); k++){
				ans += pre_time+(pre_loc-1)-Elevator[k];
			}
			Elevator.clear();
			Elevator.push_back(info[i].time);
		}else{
			if(Elevator.size() == Limit){
				printf("-1\n");
				return 0;
			}
			Elevator.push_back(info[i].time);
		}
		pre_time = info[i].time;
		pre_loc = info[i].loc;
	}

	for(int i = 0; i < Elevator.size(); i++){
		ans += pre_time+(pre_loc-1)-Elevator[i];
	}

	printf("%lld\n",ans);

	return 0;
}