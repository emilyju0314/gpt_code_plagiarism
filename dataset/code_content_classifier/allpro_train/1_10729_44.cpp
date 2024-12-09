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
//#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

#define BIG_NUM 999999999999
#define NUM 100000


struct Edge{
	int from,to;
	ll cost;
};

struct Data{
	Data(int arg_node_id,ll arg_sum_cost){
		node_id = arg_node_id;
		sum_cost = arg_sum_cost;
	}

	bool operator<(const struct Data &arg) const{
		return sum_cost > arg.sum_cost;
	}
	int node_id;
	ll sum_cost;
};

struct Info{
	Info(int arg_to,ll arg_cost,int arg_edge_id){
		to = arg_to;
		cost = arg_cost;
		edge_id = arg_edge_id;
	}
	int to,edge_id;
	ll cost;
};

map<string,int> MAP;

int V,E,number;
int order[NUM],lowlink[NUM];
ll min_cost[NUM],rev_min_cost[NUM];
bool visited[NUM],in_MIN_PATH[NUM];
Edge edge[NUM];
vector<Info> G[NUM],rev_G[NUM],MIN_G[NUM];

void recursive(int node_id){

	order[node_id] = number++;
	lowlink[node_id] = order[node_id];

	int next_node;

	for(int i = 0; i < MIN_G[node_id].size(); i++){

		next_node = MIN_G[node_id][i].to;

		if(order[next_node] == -1){

			visited[MIN_G[node_id][i].edge_id] = true;
			recursive(next_node);
			lowlink[node_id] = min(lowlink[node_id],lowlink[next_node]);

		}else if(visited[MIN_G[node_id][i].edge_id] == false){

			lowlink[node_id] = min(lowlink[node_id],order[next_node]);
		}
	}
}

void dijkstra_NORMAL(){
	int start = 0,goal = 1;

	for(int i = 0; i < V; i++)min_cost[i] = BIG_NUM;
	min_cost[start] = 0;

	priority_queue<Data> Q;

	Q.push(Data(start,0));

	int next_node;

	while(!Q.empty()){

		if(Q.top().node_id == goal){
			Q.pop();
		}else if(Q.top().sum_cost > min_cost[Q.top().node_id]){
			Q.pop();
		}else{

			for(int i = 0; i < G[Q.top().node_id].size(); i++){
				next_node = G[Q.top().node_id][i].to;

				if(min_cost[next_node] > Q.top().sum_cost+G[Q.top().node_id][i].cost){

					min_cost[next_node] = Q.top().sum_cost+G[Q.top().node_id][i].cost;
					Q.push(Data(next_node,min_cost[next_node]));
				}
			}
			Q.pop();
		}
	}
}

void dijkstra_REVERSE(){
	int start = 1,goal = 0;

	for(int i = 0; i < V; i++)rev_min_cost[i] = BIG_NUM;
	rev_min_cost[start] = 0;

	priority_queue<Data> Q;

	Q.push(Data(start,0));

	int next_node;

	while(!Q.empty()){

		if(Q.top().node_id == goal){
			Q.pop();
		}else if(Q.top().sum_cost > rev_min_cost[Q.top().node_id]){
			Q.pop();
		}else{

			for(int i = 0; i < rev_G[Q.top().node_id].size(); i++){
				next_node = rev_G[Q.top().node_id][i].to;

				if(rev_min_cost[next_node] > Q.top().sum_cost+rev_G[Q.top().node_id][i].cost){

					rev_min_cost[next_node] = Q.top().sum_cost+rev_G[Q.top().node_id][i].cost;
					Q.push(Data(next_node,rev_min_cost[next_node]));
				}
			}
			Q.pop();
		}
	}
}

int main(){

	scanf("%d %d",&V,&E);

	for(int i = 0; i < E; i++){
		scanf("%d %d %lld",&edge[i].from,&edge[i].to,&edge[i].cost);
		edge[i].from--;
		edge[i].to--;
		G[edge[i].from].push_back(Info(edge[i].to,edge[i].cost,i));
		rev_G[edge[i].to].push_back(Info(edge[i].from,edge[i].cost,i));
	}

	dijkstra_NORMAL();
	dijkstra_REVERSE();

	int goal = 1;

	for(int i = 0; i < E; i++)in_MIN_PATH[i] = false;

	string tmp_str;

	for(int i = 0; i < E; i++){

		if(min_cost[edge[i].from]+edge[i].cost+rev_min_cost[edge[i].to] == min_cost[goal]){
			in_MIN_PATH[i] = true;
			MIN_G[edge[i].from].push_back(Info(edge[i].to,edge[i].cost,i));
			MIN_G[edge[i].to].push_back(Info(edge[i].from,edge[i].cost,i));

			tmp_str.clear();
			tmp_str = tmp_str.append(to_string(edge[i].from)).append(to_string('@')).append(to_string(edge[i].to));

			auto at = MAP.find(tmp_str);

			if(at != MAP.end()){
				MAP[tmp_str]++;
			}else{
				MAP[tmp_str] = 1;
			}
		}
	}

	number = 0;

	for(int i = 0; i < V; i++){
		order[i] = -1;
		lowlink[i] = -1;
	}

	for(int i = 0; i < E; i++){
		visited[i] = false;
	}
	recursive(0);


	int from,to;

	for(int i = 0; i < E; i++){

		if((min_cost[edge[i].to] != BIG_NUM) && (rev_min_cost[edge[i].from] != BIG_NUM)
				&& (min_cost[edge[i].to]+edge[i].cost+rev_min_cost[edge[i].from]) <= min_cost[goal]){

			if(min_cost[edge[i].to]+edge[i].cost+rev_min_cost[edge[i].from] < min_cost[goal]){
				printf("HAPPY\n");
			}else{
				printf("SOSO\n");
			}
			continue;
		}

		if(in_MIN_PATH[i] == false){
			printf("SOSO\n");
			continue;
		}

		tmp_str.clear();
		tmp_str = tmp_str.append(to_string(edge[i].from)).append(to_string('@')).append(to_string(edge[i].to));
		if(MAP[tmp_str] > 1){
			printf("SOSO\n");
			continue;
		}

		from = edge[i].from;
		to = edge[i].to;
		if(order[to] < order[from]){
			swap(from,to);
		}
		if(order[from] < lowlink[to]){
			printf("SAD\n");
			continue;
		}

		printf("SOSO\n");
	}

	return 0;
}

