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

#define BIG_NUM 999999999999999
#define NUM 3000


//辺を表す構造体(行先、容量、逆辺のインデックス)
struct Edge{
	Edge(int arg_to,ll arg_capacity,int arg_rev_index){
		to = arg_to;
		capacity = arg_capacity;
		rev_index = arg_rev_index;
	}
	int to,rev_index;
	ll capacity;
};

int V,E;
int N;
ll W;
vector<Edge> G[NUM]; //グラフの隣接リスト表現
ll dist[NUM]; //sourceからの距離
int cheked_index[NUM]; //どこまで調べ終わったか

//fromからtoへ向かう容量capacityの辺をグラフに追加する
void add_edge(int from,int to,ll capacity){
	G[from].push_back(Edge(to,capacity,G[to].size()));
	G[to].push_back(Edge(from,0,G[from].size()-1)); //逆辺の、初期容量は0
}

//sourceからの最短距離をBFSで計算する
void bfs(int source){
	for(int i = 0; i < V; i++)dist[i] = -1;
	queue<int> Q;
	dist[source] = 0;
	Q.push(source);

	while(!Q.empty()){
		int node_id = Q.front();
		Q.pop();
		for(int i = 0; i < G[node_id].size(); i++){
			Edge &e = G[node_id][i];
			if(e.capacity > 0 && dist[e.to] < 0){ //辺の容量が正で、かつエッジの行先に未訪問の場合
				dist[e.to] = dist[node_id]+1;
				Q.push(e.to);
			}
		}
	}
}

//増加パスをDFSで探す
ll dfs(int node_id,int sink,ll flow){
	if(node_id == sink)return flow; //終点についたらflowをreturn

	for(int &i = cheked_index[node_id]; i < G[node_id].size(); i++){ //node_idから出ているエッジを調査
		Edge &e = G[node_id][i];
		if(e.capacity > 0 && dist[node_id] < dist[e.to]){ //流せる余裕があり、かつsourceからの距離が増加する方法である場合
			ll tmp_flow = dfs(e.to,sink,min(flow,e.capacity)); //流せるだけ流す
			if(tmp_flow > 0){ //流せた場合
				e.capacity -= tmp_flow; //流した分、エッジの容量を削減する
				G[e.to][e.rev_index].capacity += tmp_flow; //逆辺の容量を、流した分だけ増加させる
				return tmp_flow;
			}
		}
	}
	return 0;
}


//sourceからsinkへの最大流を求める
ll max_flow(int source,int sink){ //source:始点 sink:終点
	ll flow = 0,add;
	while(true){ //増加パスが存在する限り、流量を追加し続ける
		bfs(source);
		if(dist[sink] < 0)break; //sourceからsinkへと辿り着く残余グラフがない、つまり増加パスが無くなった場合、break
		for(int i = 0; i < V; i++)cheked_index[i] = 0;
		while((add = dfs(source,sink,BIG_NUM)) > 0){ //増加パスが見つかる間、加算
			flow += add;
		}
	}
	return flow;
}

void func(){

	for(int i = 0; i < NUM; i++)G[i].clear();
	int source = 0,sink = 1;

	//月～日に、容量Wの辺を張る
	for(int node_id = 2; node_id <= 8; node_id++){
		add_edge(source,node_id,W);
	}

	int index = 9;

	ll total_need = 0,need_num;
	int num;
	char buf[20];

	for(int loop = 0; loop < N; loop++){
		scanf("%lld %d",&need_num,&num);
		add_edge(index,sink,need_num); //生徒からsinkへ容量need_numの辺を張る
		total_need += need_num;

		for(int i = 0; i < num; i++){
			scanf("%s",buf);

			switch(buf[0]){ //都合の良い曜日から、生徒へ容量Wの辺を張る
			case 'M':
				add_edge(2,index,W);
				break;
			case 'T':
				if(buf[1] == 'u'){
					add_edge(3,index,W);
				}else{
					add_edge(5,index,W);
				}
				break;
			case 'W':
				add_edge(4,index,W);
				break;
			case 'F':
				add_edge(6,index,W);
				break;
			case 'S':
				if(buf[1] == 'a'){
					add_edge(7,index,W);
				}else{
					add_edge(8,index,W);
				}
				break;
			}
		}
		index++;
	}

	V = index;

	if(total_need == max_flow(source,sink)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}

int main(){

	while(true){
		scanf("%d %lld",&N,&W);
		if(N == 0 && W == 0)break;

		func();
	}

	return 0;
}

