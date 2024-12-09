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

typedef pair<int,int> P;

enum Type{
	Query,
	Event,
};

struct Info{
	Info(int arg_time,int arg_value_1,int arg_value_2,Type arg_type,int arg_query_id){
		time = arg_time;
		value_1 = arg_value_1;
		value_2 = arg_value_2;
		type = arg_type;
		query_id = arg_query_id;
	}
	bool operator<(const struct Info &arg) const{
		if(time != arg.time){
			return time > arg.time;
		}else{
			return query_id > arg.query_id;
		}
	}

	int time,value_1,value_2,query_id;
	Type type;
};

bool ans[100000];

int main(){

	int N,M,num_query;

	scanf("%d %d %d",&N,&M,&num_query);

	priority_queue<Info> Q;

	int day,from,to;
	for(int loop = 0; loop < M; loop++){
		scanf("%d %d %d",&day,&from,&to);
		Q.push(Info(day+1,from,to,Event,-1));
	}

	for(int i = 0; i < num_query; i++){
		scanf("%d %d %d",&day,&from,&to);
		Q.push(Info(day,from,to,Query,i));
	}

	set<P> SET; //区間(left-right)
	set<P>::iterator it_1,it_2,work;
	for(int i = 1; i <= N; i++)SET.insert(make_pair(i,i));
	SET.insert(make_pair(BIG_NUM,BIG_NUM));

	int new_left,new_right;
	P tmp;

	while(!Q.empty()){

		if(Q.top().type == Event){

			//printf("time:%d 工事\n",Q.top().time);

			it_1 = SET.lower_bound(make_pair(Q.top().value_1,-1));
			it_2 = SET.lower_bound(make_pair(Q.top().value_2,-1));

			tmp = *it_1;
			if(tmp.first == Q.top().value_1){ //value_1はこのグループ
				new_left = tmp.first;
			}else{ //value_1は1つ前のグループ
				it_1--;
				tmp = *it_1;
				new_left = tmp.first;
			}

			tmp = *it_2;
			if(tmp.first == Q.top().value_2){//value_2は1つ前のグループ
				new_right = tmp.second;
			}else{
				it_2--;
				tmp = *it_2;
				new_right = tmp.second;
			}

			it_2++;
			SET.erase(it_1,it_2);

			//printf("new_left:%d new_right:%d\n",new_left,new_right);
			SET.insert(make_pair(new_left,new_right));

			}else{

			if(Q.top().value_2 <= Q.top().value_1){
				ans[Q.top().query_id] = true;
				Q.pop();
				continue;
			}

			it_1 = SET.lower_bound(make_pair(Q.top().value_1,-1));
			it_2 = SET.lower_bound(make_pair(Q.top().value_2,-1));

			tmp = *it_1;
			//printf("tmp:left:%d right:%d\n",tmp.first,tmp.second);
			if(tmp.first == Q.top().value_1){ //value_1はこのグループ
				//Do nothing
			}else{ //value_1は1つ前のグループ
				it_1--;
			}

			tmp = *it_2;
			//printf("tmp:left:%d right:%d\n",tmp.first,tmp.second);
			if(tmp.first == Q.top().value_2){//value_2はこのグループ
				//Do nothing
			}else{
				it_2--;
			}

			if(it_1 == it_2){
				ans[Q.top().query_id] = true;
			}else{
				ans[Q.top().query_id] = false;
			}
		}

		Q.pop();
	}

	for(int i = 0; i < num_query; i++){
		if(ans[i]){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}

