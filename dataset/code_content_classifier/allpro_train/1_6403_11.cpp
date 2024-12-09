#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

struct Edge{
	Edge(int arg_to,ll arg_cost){
		to = arg_to;
		cost = arg_cost;
	}
	int to;
	ll cost;
};

struct Info{

	int start,day,pay;
};

struct State{

	State(int arg_node_id,int arg_sum_date,int arg_sum_cost){
		node_id = arg_node_id;
		sum_date = arg_sum_date;
		sum_cost = arg_sum_cost;
	}
	bool operator<(const struct State &arg) const{

		if(sum_cost != arg.sum_cost){

			return sum_cost > arg.sum_cost; //総コストが異なるなら昇順(PQ)
		}else{

			return sum_date > arg.sum_date; //総コストが同じなら、日数の総和(PQ)
		}
	}

	int node_id,sum_date,sum_cost;
};

int N,E,K;
int root; //根ノードの番号
int MAX_LOG_V = 17;
int POW[18];
int T[NUM];
int min_dist[NUM],min_date[NUM];
int parent[18][NUM];
int depth[NUM];
vector<Edge> G[NUM]; //グラフの隣接リスト表現
vector<int> Tree_G[NUM];
Info info[NUM];


//parentとdepthを再帰的に設定
void dfs(int node_id,int parent_id,int d){
	parent[0][node_id] = parent_id;
	depth[node_id] = d;
	for(int i = 0; i < Tree_G[node_id].size(); i++){
		if(Tree_G[node_id][i] != parent_id)dfs(Tree_G[node_id][i],node_id,d+1);
	}
}

//初期化
void init(){
	//parent[0]とdepthを初期化する
	dfs(root,-1,0);
	//parentを初期化する
	for(int k = 0; k + 1 < MAX_LOG_V; k++){
		for(int node_id = 0; node_id < N; node_id++){
			if(parent[k][node_id] < 0)parent[k+1][node_id] = -1; //node_idの2^k上のノードがルートノードより上なら、2^(k+1)上も同様とする
			else{
				parent[k+1][node_id] = parent[k][parent[k][node_id]];
			}
		}
	}
}


int main(){


	POW[0] = 1;
	for(int i = 1; i <= 17; i++){
		POW[i] = POW[i-1]*2;
	}

	scanf("%d %d",&N,&E);

	for(int i = 0; i < N; i++){

		scanf("%d",&T[i]);
	}

	int from,to,cost;

	for(int i = 0; i < E; i++){

		scanf("%d %d %d",&from,&to,&cost);
		from--;
		to--;

		G[from].push_back(Edge(to,cost));
		G[to].push_back(Edge(from,cost));
	}

	scanf("%d",&K);

	for(int i = 0; i < K; i++){

		scanf("%d %d %d",&info[i].start,&info[i].day,&info[i].pay);
		info[i].start--;
	}

	//ダイクストラ

	min_dist[0] = 0;
	min_date[0] = 0;

	for(int i = 1; i < N; i++){

		min_dist[i] = BIG_NUM;
		min_date[i] = BIG_NUM;
	}

	priority_queue<State> Q;
	Q.push(State(0,0,0));

	int next_node,next_cost,next_date;

	while(!Q.empty()){

		if((Q.top().sum_cost > min_dist[Q.top().node_id])
				|| (Q.top().sum_cost == min_dist[Q.top().node_id] && Q.top().sum_date > min_date[Q.top().node_id])){

			Q.pop();
		}else{

			for(int i = 0; i < G[Q.top().node_id].size(); i++){

				next_node = G[Q.top().node_id][i].to;
				next_cost = Q.top().sum_cost+G[Q.top().node_id][i].cost;
				next_date = Q.top().sum_date+1;

				if(min_dist[next_node] > next_cost){

					min_dist[next_node] = next_cost;
					min_date[next_node] = next_date;
					Q.push(State(next_node,next_date,next_cost));

				}else if(min_dist[next_node] == next_cost && min_date[next_node] > next_date){

					min_date[next_node] = next_date;
					Q.push(State(next_node,next_date,next_cost));
				}
			}
			Q.pop();
		}
	}

	int tmp_num,next;

	//最短経路の辺を張る
	for(int i = 1; i < N; i++){
		//次の節店を探し、辺を張る
		tmp_num = BIG_NUM;
		next = -1;

		for(int k = 0; k < G[i].size(); k++){
			if(min_dist[i]-G[i][k].cost == min_dist[G[i][k].to] && min_date[i] == min_date[G[i][k].to]+1){ //最短経路上

				if(tmp_num > T[G[i][k].to]){ //人口で選ぶ
					tmp_num = T[G[i][k].to];
					next = G[i][k].to;
				}
			}
		}

		if(next == -1)continue;

		Tree_G[next].push_back(i); //木は都市0をスタートとする
	}

	//木作り&ダブリング
	root = 0;
	init();

	int current_node,diff;

	for(int i = 0; i < K; i++){

		int ans = BIG_NUM;

		current_node = info[i].start;
		diff = depth[info[i].start]-info[i].day;

		for(int k = MAX_LOG_V-1; k >= 0; k--){
			if(diff >= POW[k]){ //たとえば深さの差が39なら、32+4+2+1のように、ノードを上方に移動させる

				current_node = parent[k][current_node];
				diff -= POW[k];
			}
		}

		if(current_node == -1){ //★金を貰う前に着く★

			ans = min(ans,min_dist[info[i].start]);

		}else{

			ans = min(ans,(min_dist[info[i].start]-min_dist[current_node])+max(0,min_dist[current_node]-info[i].pay));
		}

		printf("%d\n",ans);
	}

	return 0;
}

