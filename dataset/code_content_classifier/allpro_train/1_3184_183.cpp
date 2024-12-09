#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#define fi first
#define se second
using namespace std;
const int maxn =100003;
vector<pair<int,long long> > G[maxn];
set<pair<int,int> > S;
int son[maxn], sz[maxn];
int tree[maxn*4];
int n, tot;
long long ANS=0,Min=1e18;
void dfs0(int x,int fa){
    sz[x]=1;
	for(auto e:G[x]){
        if(e.fi==fa)continue;
        dfs0(e.fi,x);
        sz[x]+=sz[e.fi];
        son[x]=max(son[x],sz[e.fi]);
    }
    son[x]=max(son[x],n-sz[x]);
}
void dfs(int x,int fa,long long v){
    sz[x]=1;
    for(auto e:G[x]){
        if(e.fi==fa)continue;
        dfs(e.fi,x,e.se+v);
        sz[x]+=sz[e.fi];
    }
    ANS+=v;
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    int X;
    dfs0(1,1);
    for(int i=1;i<=n;i++){
    	if(son[i]<=n/2){
    		X=i;
		}
	}
    dfs(X,X,0);
    for(auto e:G[X]){
        if(sz[e.fi]==(n+1)/2){
			Min=e.se;
			break;
		}
        Min=min(e.se,Min);
    }
    cout<<ANS*2-Min<<endl;
	return 0;
}
/*

in:
8
2 8 8
1 5 1
4 8 2
2 5 4
3 8 6
6 8 9
2 7 12

out:
132

*/