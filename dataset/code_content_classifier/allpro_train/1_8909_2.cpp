#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 305

struct Edge{
	Edge(int arg_to,int arg_cost){
		to = arg_to;
		cost = arg_cost;
	}
	bool operator<(const struct Edge &arg) const{
		return to < arg.to;
	}

	int to,cost;
};

int V;
int parent;
int edge[SIZE][SIZE],ans,WORK;
int rev[SIZE];
bool is_OK;
bool visited[SIZE];
vector<Edge> G[SIZE],reserve;

void dfs(int node_id,int pre){
	if(!is_OK)return;

	if(visited[node_id]){

		is_OK = false;
		return;
	}
	visited[node_id] = true;

	if(node_id == parent){

		for(int next = 0; next < V; next++){
			if(next == pre)continue;

			if(edge[node_id][next]*rev[node_id]*rev[next] > 0){

				WORK += abs(edge[node_id][next]);
				if(WORK >= ans){
					is_OK = false;
					return;
				}

				dfs(next,node_id);
			}
		}

	}else{

		if(pre != parent && (edge[node_id][parent]*rev[node_id]*rev[parent] > 0)){

			WORK += abs(edge[node_id][parent]);
			if(WORK >= ans){
				is_OK = false;
				return;
			}

			dfs(parent,node_id);
		}

		for(int i = 0; i < G[node_id].size(); i++){

			int next = G[node_id][i].to;

			if(next == pre || next == parent)continue;

			WORK += abs(edge[node_id][next]);
			if(WORK >= ans){
				is_OK = false;
				return;
			}

			dfs(next,node_id);
		}
	}
}


void func(){

	int tmp;

	for(int from = 0; from <= V-2; from++){
		for(int to = from+1; to <= V-1; to++){
			scanf("%d",&tmp);
			edge[from][to] = tmp;
			edge[to][from] = tmp;
		}
	}

	ans = BIG_NUM;

	//葉と、その葉と繋がる節点のペアを全探索
	for(int leaf = 0; leaf < V; leaf++){

		for(int i = 0; i < V; i++){
			G[i].clear();
		}

		//反転するか否かを決定
		for(int i = 0; i < V; i++){
			if(i == leaf){

				rev[i] = -1; //葉は反転しないとしておく

			}else{

				if(edge[i][leaf] > 0){

					rev[i] = 1;

				}else{

					rev[i] = -1;
				}
			}
		}

		for(int from = 0; from <= V-2; from++){
			for(int to = from+1; to <= V-1; to++){

				if((edge[from][to]*rev[from]*rev[to]> 0)){
					G[from].push_back(Edge(to,abs(edge[from][to])));
					G[to].push_back(Edge(from,abs(edge[from][to])));
				}
			}
		}

		for(parent = 0; parent < V; parent++){

			if(parent == leaf)continue;

			int pre_rev = rev[parent];

			if(edge[parent][leaf] < 0){

				rev[parent] = 1;
			}else{

				rev[parent] = -1;
			}

			//全域木か調べる
			for(int i = 0; i < V; i++){
				visited[i] = false;
			}

			is_OK = true;
			WORK = 0;
			dfs(parent,-1);

			if(!is_OK){
				rev[parent] = pre_rev;
				continue;
			}

			bool FLG = true;
			if(is_OK){
				for(int i = 0; i < V; i++){
					if(!visited[i]){
						FLG = false;
						break;
					}
				}
			}

			if(is_OK && FLG){
				ans = min(ans,WORK);
			}

			rev[parent] = pre_rev;
		}
	}

	if(ans == BIG_NUM){

		printf("-1\n");

	}else{

		printf("%d\n",ans);
	}
}

int main(){

	while(true){
		scanf("%d",&V);
		if(V == 0)break;

		func();
	}

	return 0;
}




