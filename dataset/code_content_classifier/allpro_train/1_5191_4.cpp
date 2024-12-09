#include<bits/stdc++.h>
//typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



typedef __int128 ll;
#define NUM 105


struct Data{

    void set(ll arg_denominator,ll arg_numerator){
        denominator = arg_denominator;
        numerator = arg_numerator;
    }
    ll denominator,numerator;
};

struct Dinic{

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

    int V;

    vector<Edge> G[NUM];
    ll dist[NUM];
    int cheked_index[NUM];

    void add_edge(int from,int to,ll capacity){
        G[from].push_back(Edge(to,capacity,G[to].size()));
        G[to].push_back(Edge(from,0,G[from].size()-1));
    }

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
                if(e.capacity > 0 && dist[e.to] < 0){
                    dist[e.to] = dist[node_id]+1;
                    Q.push(e.to);
                }
            }
        }
    }

    ll dfs(int node_id,int sink,ll flow){
        if(node_id == sink)return flow;

        for(int &i = cheked_index[node_id]; i < G[node_id].size(); i++){
            Edge &e = G[node_id][i];
            if(e.capacity > 0 && dist[node_id] < dist[e.to]){
                ll tmp_flow = dfs(e.to,sink,min(flow,e.capacity));
                if(tmp_flow > 0){
                    e.capacity -= tmp_flow;
                    G[e.to][e.rev_index].capacity += tmp_flow;
                    return tmp_flow;
                }
            }
        }
        return 0;
    }

    ll max_flow(int source,int sink){
        ll flow = 0,add;
        while(true){
            bfs(source);
            if(dist[sink] < 0)break;
            for(int i = 0; i < V; i++)cheked_index[i] = 0;
            while((add = dfs(source,sink,BIG_NUM)) > 0){
                flow += add;
            }
        }
        return flow;
    }
};

struct Info{
    Info(ll arg_flow,ll arg_cost){
        flow = arg_flow;
        cost = arg_cost;
    }
    ll flow,cost;
};

struct Edge{
    Edge(int arg_to,ll arg_capacity,ll arg_cost,int arg_rev_index){
        to = arg_to;
        capacity = arg_capacity;
        cost = arg_cost;
        rev_index = arg_rev_index;
    }

    int to,rev_index;
    ll cost,capacity;
};


int V; //頂点数
vector<Edge> G[NUM]; //グラフの隣接リスト表現
ll dist[NUM]; //最短距離
int pre_node[NUM],pre_edge[NUM]; //直前の頂点と辺
vector<Info> info;



ll gcd(ll x,ll y){

	if(x < 0)x *= -1;
	if(y < 0)y *= -1;
/*
    x = abs(x);
    y = abs(y);*/

    if(x < y){
        swap(x,y);
    }
    if(y == 0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}

ll lcm(ll x,ll y){

    return (x*y)/gcd(x,y);
}

//分子・分母を約分する
Data reduction(Data A){

    ll common = gcd(A.denominator,A.numerator);

    A.denominator /= common;
    A.numerator /= common;

    return A;
}

//A+B
Data add(Data A,Data B){

    Data ret;

    ll LCM = lcm(A.denominator,B.denominator);

    ll a_mult = LCM/A.denominator;
    ll b_mult = LCM/B.denominator;

    ret.denominator = LCM;

    A.numerator *= a_mult;
    B.numerator *= b_mult;

    ret.numerator = A.numerator+B.numerator;

    return reduction(ret);
}

//A-B
Data subtract(Data A,Data B){

    Data ret;

    ll LCM = lcm(A.denominator,B.denominator);

    ll a_mult = LCM/A.denominator;
    ll b_mult = LCM/B.denominator;

    ret.denominator = LCM;

    A.numerator *= a_mult;
    B.numerator *= b_mult;

    ret.numerator = A.numerator-B.numerator;

    return reduction(ret);
}

//A*B
Data mult(Data A,Data B){

    Data ret;

    ret.numerator = A.numerator*B.numerator;
    ret.denominator = A.denominator*B.denominator;

    return reduction(ret);
}

//A/B
Data divide(Data A,Data B){

    Data ret;

    ret.numerator = A.numerator*B.denominator;
    ret.denominator = A.denominator*B.numerator;

    return reduction(ret);
}

void add_edge(int from,int to,ll capacity,ll cost){
    G[from].push_back(Edge(to,capacity,cost,G[to].size()));
    G[to].push_back(Edge(from,0,-cost,G[from].size()-1));
}

void min_cost_flow(int source,int sink,ll flow){

    info.push_back(Info(0,0));

    ll max_FLOW = flow;
    ll sum_cost = 0;

    while(flow > 0){
        //ベルマンフォード方により、source-sink間最短経路を求める
        for(int i = 0; i < V; i++)dist[i] = BIG_NUM;
        dist[source] = 0;
        bool update = true;
        while(update){
            update = false;
            for(int node_id = 0; node_id < V; node_id++){
                if(dist[node_id] == BIG_NUM)continue;
                for(int i = 0; i < G[node_id].size(); i++){
                    Edge &e = G[node_id][i];
                    if(e.capacity > 0 && dist[e.to] > dist[node_id]+e.cost){
                        dist[e.to] = dist[node_id]+e.cost; //node_idを経由した方が早い場合
                        pre_node[e.to] = node_id;
                        pre_edge[e.to] = i;
                        update = true;
                    }
                }
            }
        }

        if(dist[sink] == BIG_NUM){
            //これ以上流せない
            return;
        }

        //source-sink間最短路に沿って目いっぱい流す
        ll tmp_flow = flow;
        for(int node_id = sink; node_id != source; node_id = pre_node[node_id]){
            tmp_flow = min(tmp_flow,G[pre_node[node_id]][pre_edge[node_id]].capacity);
        }
        flow -= tmp_flow;
        sum_cost += tmp_flow*dist[sink];

        info.push_back(Info(max_FLOW-flow,sum_cost));

        for(int node_id = sink; node_id != source; node_id = pre_node[node_id]){
            Edge &e = G[pre_node[node_id]][pre_edge[node_id]];
            e.capacity -= tmp_flow;
            G[node_id][e.rev_index].capacity += tmp_flow;
        }
    }
}

__int128 input(string str) {

	__int128 ret = 0;

	for (int i = 0; i < str.length(); i++){

		if (str[i] >= '0' && str[i] <= '9'){

			ret = 10*ret+(str[i]-'0');
		}
    }

	return ret;
}

//https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

int main(){

    int E;
    Dinic dinic;

    scanf("%d %d",&V,&E);
    dinic.V = V;

    int source,sink;
    scanf("%d %d",&source,&sink);

    source--;
    sink--;

    int from,to;
    string str_capacity,str_cost;
    ll capacity,cost;

    for(int loop = 0; loop < E; loop++){

    	cin >> from >> to >> str_capacity >> str_cost;

    	from--;
    	to--;

    	capacity = input(str_capacity);
    	cost = input(str_cost);

        add_edge(from,to,capacity,cost);
        dinic.add_edge(from,to,capacity);
    }

    ll max_FLOW = dinic.max_flow(source,sink); //最大の流量を求める

    min_cost_flow(source,sink,max_FLOW); //折れ線グラフ作成

    //最大流量
    Data MAX_FLOW;
    MAX_FLOW.denominator = 1;
    MAX_FLOW.numerator = max_FLOW;

    //微分して0になる箇所がなかった場合のため、仮の答えを求めておく
    ll minimum = HUGE_NUM;

    for(int i = 0; i < info.size(); i++){

        ll tmp = info[i].cost*info[i].cost+(max_FLOW-info[i].flow)*(max_FLOW-info[i].flow);
        minimum = min(minimum,tmp);
    }

    //左端流量からの追加流量で目的関数を微分して、0になる区間があるかどうか調べる
    for(int i = 0; i < info.size()-1; i++){

        //その区間の傾き
        Data slope;
        slope.set(info[i+1].flow-info[i].flow,info[i+1].cost-info[i].cost); //(分母,分子)の順
        slope = reduction(slope);

        /*左端流量-最大流量+区間傾き*左端コスト < 0 < 右端流量-最大流量+区間傾き*右端コストが成り立つか調べる*/

        Data left;
        left.set(1,info[i].flow);

        left = subtract(left,MAX_FLOW);

        Data tmp;
        tmp.set(slope.denominator,slope.numerator*info[i].cost);
        tmp = reduction(tmp);

        left = add(left,tmp);

        if(left.numerator >= 0)continue;

        Data right;
        right.set(1,info[i+1].flow);

        right = subtract(right,MAX_FLOW);

        tmp.set(slope.denominator,slope.numerator*info[i+1].cost);
        tmp = reduction(tmp);

        right = add(right,tmp);

        if(right.numerator <= 0)continue;

        //解あり→追加流量を求める
        Data DENOMINATOR = mult(slope,slope);

        tmp.set(1,1);

        DENOMINATOR = add(DENOMINATOR,tmp);

        Data NUMERATOR;
        NUMERATOR.set(1,max_FLOW-info[i].flow);

        tmp.set(slope.denominator,slope.numerator*info[i].cost);
        tmp = reduction(tmp);

        NUMERATOR = subtract(NUMERATOR,tmp);

        Data delta = divide(NUMERATOR,DENOMINATOR);

        Data L = MAX_FLOW;

        tmp.set(1,info[i].flow);
        tmp = add(tmp,delta);

        L = subtract(L,tmp);
        L = mult(L,L);

        Data R;
        R.set(1,info[i].cost);

        tmp = slope;
        tmp = mult(tmp,delta);

        R = add(R,tmp);
        R = mult(R,R);

        Data ans = add(L,R);

        cout << ans.numerator << "/" << ans.denominator << endl;

        return 0;
    }

    cout << minimum << "/1" << endl;


    return 0;
}

