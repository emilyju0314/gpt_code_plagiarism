#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)

#define MAX_N 200100
#define MAX_LOG_V 20
 
const int SIZE = 1<<19;
struct node{
	ll l,m,r,sum,lazy,ig;
	node(){
		l = m = r = sum = ig = 0;
		lazy = INF;
	}
	node(ll _ig){
		l = m = r = sum = 0;
		lazy = INF;
		ig = _ig;
	}
};
node update_node(node lch,node rch){
	if(lch.ig)return rch;
	if(rch.ig)return lch;
	node ret;
	ret.m = max(max(lch.m,rch.m),lch.r+rch.l);
	ret.l = max(lch.l,lch.sum+rch.l);
	ret.r = max(rch.r,lch.r+rch.sum);
	ret.sum = lch.sum+rch.sum;
	return ret;
}
void prnode(node v){
	//printf("%d %d %d %d\n",v.l,v.m,v.r,v.sum);
}
struct segtree{
    node seg[SIZE*2];
    void lazy_evaluate(int k,int l,int r){
    	if(seg[k].lazy==INF)return;
        seg[k].m = max(seg[k].lazy*(r-l),seg[k].lazy);
        seg[k].l = seg[k].m;
        seg[k].r = seg[k].m;
        seg[k].sum = seg[k].lazy*(r-l);
        if(k<SIZE-1){
            seg[k*2+1].lazy = seg[k].lazy;
            seg[k*2+2].lazy = seg[k].lazy;
        }
        seg[k].lazy=INF;
    }
    void update(int a,int b,int k,int l,int r,ll x){
        lazy_evaluate(k,l,r);
        if(r<=a||b<=l)return;
        else if(a<=l&&r<=b){
            seg[k].lazy = x;
            lazy_evaluate(k,l,r);
            return;
        }else{
            update(a,b,k*2+1,l,(l+r)/2,x);
            update(a,b,k*2+2,(l+r)/2,r,x);
            seg[k] = update_node(seg[k*2+1],seg[k*2+2]);
        }
    }
    void update(int a,int b,ll x){
    	if(a>=b)return;
        update(a,b,0,0,SIZE,x);
    }
    node query(int a,int b,int k,int l,int r){
        lazy_evaluate(k,l,r);
        if(r<=a||b<=l)return node(1);
        else if(a<=l&&r<=b)return seg[k];
        else{
            node lch = query(a,b,k*2+1,l,(l+r)/2);
            node rch = query(a,b,k*2+2,(l+r)/2,r);
            seg[k] = update_node(seg[k*2+1],seg[k*2+2]);
            return update_node(lch,rch);
        }
    }
   	node query(int a,int b){
   		if(a>=b)return node(1);
        return query(a,b,0,0,SIZE);
    }
}seg;
struct HeavyLightDecomposition{
    vector<int> g[MAX_N];
    int N,root;
    int par[MAX_N];
    int depth[MAX_N],chnum[MAX_N];
    void add_edge(int a,int b){
        g[a].pb(b);
        g[b].pb(a);
    }
    struct state{
        int v,p,d;
        bool go;
        state(int v,int p,int d,bool go):v(v),p(p),d(d),go(go){}
        state(int v,int p,bool go):v(v),p(p),go(go){}
    };
    void init(){
        dfs();
        decompose();
        construct_toseg();
    }
    void dfs(){
        stack<state> st;
        st.push(state(0,-1,0,true));
        while(!st.empty()){
            state now = st.top();
            st.pop();
            int v = now.v,p = now.p,d = now.d;
            if(now.go){
                depth[v]=d;
                par[v]=p;
                st.push(state(v,p,d,false));
                for(int i=0;i<g[v].size();i++){
                    if(g[v][i]==p)continue;
                    st.push(state(g[v][i],v,d+1,true));
                }
            }else{
                chnum[v]=1;
                for(int i=0;i<g[v].size();i++){
                    chnum[v]+=chnum[g[v][i]];
                }
            }
        }
        return;
    }
    vector<int> top;
    int head[MAX_N];
    int heavy[MAX_N];
    int toseg[MAX_N];
    int chain_len[MAX_N];
    void decompose(){
        stack<state> st;
        st.push(state(0,-1,true));
        while(!st.empty()){
            state now = st.top();
            st.pop();
            int v=now.v,p=now.p,istop=now.go;
            if(istop)top.pb(v);
            int hev = -1;
            int val = -1;
            for(int i=0;i<g[v].size();i++){
                if(g[v][i]==p)continue;
                if(val<chnum[g[v][i]]){
                    val = chnum[g[v][i]];
                    hev = g[v][i];
                }
            }
            heavy[v]=hev;
            for(int i=0;i<g[v].size();i++){
                if(g[v][i]==p)continue;
                if(g[v][i]==hev)st.push(state(g[v][i],v,false));
                else st.push(state(g[v][i],v,true));
            }
        }
    }
    void construct_toseg(){
        int id = 0;
        for(int i=0;i<top.size();i++){
            int now = top[i];
            while(1){
                if(now==-1)break;
                toseg[now]=id++;
                head[now]=top[i];
                now = heavy[now];
                chain_len[top[i]]++;
            }
        }
    }
    int lca(int u,int v){
        while(head[u]!=head[v]){
            if(depth[head[u]]<depth[head[v]])swap(u,v);
            u = par[head[u]];
        }
        return (depth[u]<depth[v])?u:v;
    }
    void update(int u,int v,int x){
    	if(u==v){
    		seg.update(toseg[u],toseg[u]+1,x);
    		return;
    	}
    	int lc = lca(u,v);
    	int nu = u,nv = v;
    	while(depth[head[nu]]>depth[lc]){
            seg.update(toseg[head[nu]],toseg[nu]+1,x);
            nu = par[head[nu]];
        }
        seg.update(toseg[lc],toseg[nu]+1,x);
    	while(depth[head[nv]]>depth[lc]){
            seg.update(toseg[head[nv]],toseg[nv]+1,x);
            nv = par[head[nv]];
        }
        seg.update(toseg[lc],toseg[nv]+1,x);
    }
    ll query(int u,int v){
    	if(u==v)return seg.query(toseg[u],toseg[u]+1).m;
    	int lc = lca(u,v);
    	int nu=u,nv=v;
    	node ansu = node(1);
    	node ansv = node(1);
    	while(depth[head[nu]]>depth[lc]){
    		//printf("[ %d %d ]\n",nu,head[nu]);
            ansu = update_node(seg.query(toseg[head[nu]],toseg[nu]+1),ansu);
            nu = par[head[nu]];
        }
        bool flag = false;
        if(nu!=lc){
        	//printf("[ %d %d ]\n",nu,lc);
        	ansu = update_node(seg.query(toseg[lc],toseg[nu]+1),ansu);
        	flag = true;
        }
        //prnode(ansu);
    	while(depth[head[nv]]>depth[lc]){
    		//printf("[ %d %d ]\n",nv,head[nv]);
            ansv = update_node(seg.query(toseg[head[nv]],toseg[nv]+1),ansv);
            nv = par[head[nv]];
        }
        if(!flag){
        	//printf("[ %d %d ]\n",nv,lc);
        	ansv = update_node(seg.query(toseg[lc],toseg[nv]+1),ansv);
        }
        //prnode(ansv);
        swap(ansu.l,ansu.r);
        node ans = update_node(ansu,ansv);
        //prnode(ans);
        return ans.m;       
    }
}hld;
 
int N,Q;
ll w[200100];
int main(){
    /*while(1){
        int t,u,v,x;
        scanf("%d %d %d",&t,&u,&v);
        if(t==2)printf("%d\n",seg.query(u,v).m);
        else{
            scanf("%d",&x);
            seg.update(u,v,x);
        }
    }*/
    scanf("%d %d",&N,&Q);
    hld.N = N;
    for(int i=0;i<N;i++)scanf("%lld",&w[i]);
    for(int i=0;i<N-1;i++){
        hld.add_edge(i,i+1);
    }
    hld.root = 0;
    hld.init();
    /*for(int i=0;i<N;i++){
        printf("%d %d %d %d %d\n",i,head[i],heavy[i],toseg[i],chain_len[i]);
    }*/
    for(int i=0;i<N;i++)hld.update(i,i,w[i]);
    printf("%lld\n",max(0ll,hld.query(0,N-1)));
    for(int i=0;i<Q;i++){
        int k;
        ll x;
        scanf("%d %lld",&k,&x);
        k--;
        hld.update(k,k,x);
        printf("%lld\n",max(0ll,hld.query(0,N-1)));
    }
    return 0;
}

