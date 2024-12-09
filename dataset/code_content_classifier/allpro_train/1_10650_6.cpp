#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

int n,m;
int c[100001];
int f[100001],t[100001];
vector<int> G[100001];
vector<int> rG[100001];
vector<int> vs;
vector<int> lis[100001];
bool used[100001];
int cmp[100001]; 
bool notbi[100001];
int color[100001];
int sum[100001][2];
int dp[100001][2][2];
vector<PP> sccG[100001];

void dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k){
	used[v]=true;
	cmp[v]=k;
	lis[k].push_back(v);
	for(int i=0;i<rG[v].size();i++){
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}

int scc(){
	memset(used,false,sizeof(used));
	vs.clear();
	for(int v=0;v<n;v++){
		if(!used[v])dfs(v);
	}
	memset(used,false,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--){
		if(!used[vs[i]])rdfs(vs[i],k++);
	}
	return k;
}

bool check(int v,int ord,int c){
	color[v]=c;
	for(int i=0;i<G[v].size();i++){
		int nv=G[v][i];
		if(ord!=cmp[nv])continue;
		if(c==color[nv])return false;
		if(color[nv]==0 && !check(nv,ord,-c))return false;
	}
	for(int i=0;i<rG[v].size();i++){
		int nv=rG[v][i];
		if(ord!=cmp[nv])continue;
		if(c==color[nv])return false;
		if(color[nv]==0 && !check(nv,ord,-c))return false;
	}
	return true;
}

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&f[i],&t[i]);
		G[f[i]].push_back(t[i]);
		rG[t[i]].push_back(f[i]);
	}
	int k=scc();
	for(int i=0;i<n;i++){
		if(color[i]==0 && !notbi[cmp[i]]){
			if(!check(i,cmp[i],1)){
				notbi[cmp[i]]=true;
			}
		}
	}
	for(int i=0;i<m;i++){
		int sf=cmp[f[i]];
		int st=cmp[t[i]];
		if(sf==st)continue;
		sccG[sf].push_back(PP(st,P(f[i],t[i])));
	}
	for(int i=0;i<k;i++){
		if(notbi[i]){
			int s=0;
			for(int j=0;j<lis[i].size();j++){
				s+=c[lis[i][j]];
			}
			sum[i][0]=s;
			sum[i][1]=s;
		}else{
			for(int j=0;j<lis[i].size();j++){
				if(color[lis[i][j]]==1)sum[i][0]+=c[lis[i][j]];
				else sum[i][1]+=c[lis[i][j]];
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[cmp[0]][0][0]=0;
	int res=0;
	for(int i=0;i<k;i++){
		for(int j=0;j<2;j++){
			for(int l=0;l<2;l++){
				if(dp[i][j][l]>=0){
					if(notbi[i]){
						dp[i][j][l]+=sum[i][0];
					}else{
						dp[i][j][l]+=sum[i][(j+l)%2];
					}
					res=max(dp[i][j][l],res);
					//printf("%d %d %d %d\n",i,j,l,dp[i][j][l]);
					for(int a=0;a<sccG[i].size();a++){
						int nv=sccG[i][a].first;
						int nf=sccG[i][a].second.first;
						int nt=sccG[i][a].second.second;
						int ncol=0;
						if(color[nt]==-1)ncol=1;
						int pcol=0;
						if(color[nf]==-1)pcol=1;
						if(notbi[i]){
							dp[nv][ncol][0]=max(dp[nv][ncol][0],dp[i][j][l]);
							dp[nv][ncol][1]=max(dp[nv][ncol][1],dp[i][j][l]);
						}else{
							int nn=1-l;
							int n2=abs(pcol-j);
							nn=(nn+n2)%2;
							dp[nv][ncol][nn]=max(dp[nv][ncol][nn],dp[i][j][l]);
						}
					}
				}
			}
		}
	}
	printf("%d\n",res);
	return 0;
}