#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

struct PrimalDual{
    using F=long long;
    const F INF=1ll<<50;
    
    struct Edge{
        int to;
        F cap,cost;
        int rev;
        Edge(int to,F cap,F cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
    };
    
    int n;
    vector<vector<Edge>>G;

    PrimalDual(int n):n(n),G(n){}

    void addEdge(int from,int to,F cap,F cost){
        G[from].push_back(Edge(to,cap,cost,G[to].size()));
        G[to].push_back(Edge(from,0,-cost,G[from].size()-1));
    }


    double solve(int s,int t,F P){
        F cur=0;

        vector<F>h(n);
        vector<int>prevv(n,-1),preve(n,-1);
        vector<F>dist(n);
        priority_queue<pair<F,int>,vector<pair<F,int>>,greater<pair<F,int>>>que;
        
		double ans=1e10;
        for(int z=1;;z++){
            fill(dist.begin(),dist.end(),INF);
            dist[s]=0;
            que.emplace(0,s); 
            while(que.size()){
                F d;
                int v;
                tie(d,v)=que.top();
                que.pop();
                if(dist[v]<d)continue;
                for(int i=0;i<G[v].size();i++){
                    Edge &e=G[v][i];
                    F nd=dist[v]+e.cost+h[v]-h[e.to];
                    if(e.cap>0&&dist[e.to]>nd){
                        dist[e.to]=nd;
                        prevv[e.to]=v;preve[e.to]=i;
                        que.emplace(nd,e.to);
                    }
                }
            }
            if(dist[t]==INF)break;
            for(int v=0;v<n;v++)h[v]+=dist[v];
            cur+=h[t];
            for(int v=t;v!=s;v=prevv[v]){
                Edge &e=G[prevv[v]][preve[v]];
                e.cap-=1;
                G[v][e.rev].cap+=1;
            }
			chmin(ans,1.0*(cur+P)/z);
        }
		return ans;
    }
};



signed main(){
	int N,M,P,S,T;
	cin>>N>>M>>P>>S>>T;
	S--;T--;

	PrimalDual pd(N);
	rep(i,M){
		int u,v,d,c;
		cin>>u>>v>>d>>c;
		u--;v--;
		pd.addEdge(u,v,c,d);
	}

	printf("%.20f\n",pd.solve(S,T,P));
	return  0;
}
