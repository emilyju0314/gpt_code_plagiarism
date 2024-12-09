#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 1000
#define HUGE_NUM 9999999999999999


struct Edge{
	Edge(int arg_to,ll arg_cost_1,ll arg_cost_2){
		to = arg_to;
		cost_1 = arg_cost_1;
		cost_2 = arg_cost_2;
	}
	int to;
	ll cost_1,cost_2;
};

struct State{
	State(int arg_node_1,int arg_node_2,ll arg_sum_cost){
		node_1 = arg_node_1;
		node_2 = arg_node_2;
		sum_cost = arg_sum_cost;
	}
	bool operator<(const struct State & arg) const{ //総コストの昇順(PQ)
		return sum_cost > arg.sum_cost;
	}
	int node_1,node_2;
	ll sum_cost;

};

int V,E;
int in_num[NUM],topo_order[NUM];
vector<Edge> G[NUM];
ll min_dist[NUM][NUM];


int main(){

	scanf("%d %d",&V,&E);

	int start = 0,goal = V-1;

	int from,to;
	ll cost_1,cost_2;

	for(int i = 0; i < V; i++)in_num[i] = 0;

	for(int loop = 0; loop < E; loop++){
		scanf("%d %d %lld %lld",&from,&to,&cost_1,&cost_2);
		from--;
		to--;
		in_num[to]++; //トポロジカル順序を計算するため
		G[from].push_back(Edge(to,cost_1,cost_2));
	}

	int index = 0,next_node;

	queue<int> Q;
	Q.push(start);

	//各ノードのトポロジカル順序を求める
	while(!Q.empty()){

		topo_order[Q.front()] = index++;

		for(int i = 0; i < G[Q.front()].size(); i++){
			next_node = G[Q.front()][i].to;
			in_num[next_node]--;

			if(in_num[next_node] == 0){
				Q.push(next_node);
			}
		}
		Q.pop();
	}

	for(int i = 0; i < V; i++){
		for(int k = 0; k < V; k++)min_dist[i][k] = HUGE_NUM; //min_dist[1回目の終端][2回目の終端] = 合計最短コスト
	}

	min_dist[start][start] = 0;
	priority_queue<State> PQ;
	PQ.push(State(start,start,0));

	int next_node_1,next_node_2,next_cost;

	while(!PQ.empty()){

		if(PQ.top().sum_cost > min_dist[PQ.top().node_1][PQ.top().node_2]){
			PQ.pop();
			continue;
		}

		if(PQ.top().node_1 == PQ.top().node_2){

			if(PQ.top().node_1 == goal){
				printf("%lld\n",PQ.top().sum_cost);
				return 0;
			}

			//同じエッジを下る場合
			for(int i = 0; i < G[PQ.top().node_1].size(); i++){

				next_node_1 = G[PQ.top().node_1][i].to;
				next_node_2 = next_node_1;
				next_cost = PQ.top().sum_cost+G[PQ.top().node_1][i].cost_1+G[PQ.top().node_1][i].cost_2;

				if(min_dist[next_node_1][next_node_2] > next_cost){
					min_dist[next_node_1][next_node_2] = next_cost;
					PQ.push(State(next_node_1,next_node_2,next_cost));
				}
			}


			if(G[PQ.top().node_1].size() == 1){
				PQ.pop();
				continue;
			}
			//違うエッジを下る場合
			for(int i = 0; i < G[PQ.top().node_1].size(); i++){

				next_node_1 = G[PQ.top().node_1][i].to;

				for(int k = 0; k < G[PQ.top().node_1].size(); k++){
					if(k == i)continue;

					next_node_2 = G[PQ.top().node_1][k].to;
					next_cost = PQ.top().sum_cost+G[PQ.top().node_1][i].cost_1+G[PQ.top().node_1][k].cost_1;

					if(min_dist[next_node_1][next_node_2] > next_cost){
						min_dist[next_node_1][next_node_2] = next_cost;
						PQ.push(State(next_node_1,next_node_2,next_cost));
					}
				}
			}

		}else{

			//トポロジカルソート順が小さい方のノードを進める
			if(topo_order[PQ.top().node_1] <= topo_order[PQ.top().node_2]){

				for(int i = 0; i < G[PQ.top().node_1].size(); i++){

					next_node_1 = G[PQ.top().node_1][i].to;
					next_node_2 = PQ.top().node_2;
					next_cost = PQ.top().sum_cost+G[PQ.top().node_1][i].cost_1;

					if(min_dist[next_node_1][next_node_2] > next_cost){
						min_dist[next_node_1][next_node_2] = next_cost;
						PQ.push(State(next_node_1,next_node_2,next_cost));
					}
				}

			}else{

				for(int i = 0; i < G[PQ.top().node_2].size(); i++){

					next_node_2 = G[PQ.top().node_2][i].to;
					next_node_1 = PQ.top().node_1;
					next_cost = PQ.top().sum_cost+G[PQ.top().node_2][i].cost_1; //★初めて通るとして良い★

					if(min_dist[next_node_1][next_node_2] > next_cost){
						min_dist[next_node_1][next_node_2] = next_cost;
						PQ.push(State(next_node_1,next_node_2,next_cost));
					}
				}
			}
		}
		PQ.pop();
	}

	return 0;
}

