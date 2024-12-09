#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T> class Dinic {
public:
    struct edge{
        int to;
        T cap;
        int rev;
    };
    vector<vector<edge> > G;
    vector<int> level,iter;
    int n;
    Dinic(int node_size){
        n = node_size;
        G.resize(node_size),level.resize(node_size),iter.resize(node_size);
    }
    //辺を張る
    void add_edge(int from,int to,T cap)
    {
    	G[from].push_back((edge){to,cap,(int)G[to].size()});
    	G[to].push_back((edge){from,(T)0,(int)G[from].size()-1});
    }
    void bfs(int s)
    {
    	fill(level.begin(),level.end(),-1);
    	queue<int> que;
    	level[s] = 0;
    	que.push(s);
    	while(!que.empty()){
    		int v = que.front();
    		que.pop();
    		for(auto& e : G[v]){
    			if(e.cap > 0 && level[e.to] < 0){
    				level[e.to] = level[v] + 1;
    				que.push(e.to);
    			}
    		}
    	}
    }
    T dfs(int v,int t,T f)
    {
    	if(v==t){
    		return f;
    	}
    	for(int &i = iter[v];i<(int)G[v].size();i++){
    		edge &e = G[v][i];
    		if(e.cap > 0 && level[v] < level[e.to]){
    			T d = dfs(e.to,t,min(f,e.cap));
    			if(d>0){
    				e.cap -= d;
    				G[e.to][e.rev].cap += d;
    				return d;
    			}
    		}
    	}
    	return 0;
    }
    //最大流を計算
    T solve(int s,int t)
    {
    	T flow = 0;
    	for(;;){
    		bfs(s);
    		if(level[t]<0){
    			return flow;
    		}
    		fill(iter.begin(),iter.end(),0);
    		T f;
    		while((f=dfs(s,t,numeric_limits<T>::max())) > 0){
    			flow += f;
    		}
    	}
    }
};


int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n)cin >> s[i];
    
    for(int i=0;i<26;i++){
        Dinic<int> dc(30);
        int cnt = 0;
        bool flag = 0;
        for(int j=0;j<n;j++){
            char a,b;
            a = s[j][0];
            b = s[j][s[j].size()-1];
            if(s[j][0]=='a'+i){
                if(b=='a'+i){
                    flag = 1;
                }else{
                    cnt++;
                    dc.add_edge(0,b-'a',1);
                }
            }else{
                if(b=='a'+i){
                    flag = 1;
                    dc.add_edge(a-'a',27,1);
                }else{
                    dc.add_edge(a-'a',b-'a',1);
                }
            }
        }
        int ans = dc.solve(0,27);
        if(!flag){
            continue;
        }
        if(ans>=cnt){
            cout << (char)('a'+i) << endl;
        }else{
            continue;
        }
    }

    return 0;
}
