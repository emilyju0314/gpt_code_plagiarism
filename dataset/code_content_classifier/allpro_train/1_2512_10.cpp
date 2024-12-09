#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define line printf("\n")
#define rep(a,b,c) for(int a= (int)b;a<(int)c;a++)
#define repd(a,b,c) for(int a=(int)b;a>=c;a--)
#define pb push_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define pq priority_queue
#define haha printf("hahaha\n")

const int INF = 1e9+7;
const ll INFLL = 1e17;
const double EPS = 1e-5;

using namespace std;

vector<int> adj[3005];
pair<int,int> edge[30005];
int flag[3005],deg[3005];
int n,m,d,rem;
inline void upg(int &a,int b){
	if(a<b)a = b;
}
int brute(int i,int sisa){
	int ret = -1;

	for(int k=i;k<m;k++){
		int a = edge[k].first;
		int b = edge[k].second;
		if(flag[a] || flag[b])continue;
		if(sisa==0)return -1;
		if(deg[a]<deg[b])swap(a,b);
		vector<int>reset;
		//use a
		flag[a] = 1;
		for(int l=0;l<adj[a].size();l++){
			if(!flag[adj[a][l]]){
				deg[adj[a][l]]--;
				reset.push_back(adj[a][l]);
			}
		}
		if(sisa-1>ret && !(deg[a]<=1 && deg[b]>1))upg(ret,brute(i+1,sisa-1));
		
		//not use a
		flag[a] = 0;
		for(int l=0;l<reset.size();l++)deg[reset[l]]++;
		reset.clear();
		
		for(int l=0;l<adj[a].size();l++){
			if(!flag[adj[a][l]]){
				sisa--;
				flag[adj[a][l]] = 1;
				reset.push_back(adj[a][l]);
			}
		}	
		for(int l=0;l<reset.size();l++){
			for(int j=0;j<adj[reset[l]].size();j++)deg[adj[reset[l]][j]]--;
		}
		
		if(sisa>ret && !(deg[a]>1&&deg[b]<=1))upg(ret,brute(i+1,sisa));
		for(int l=0;l<reset.size();l++){
			flag[reset[l]] = 0;
			for(int j=0;j<adj[reset[l]].size();j++)deg[adj[reset[l]][j]]++;
		}
		
		return ret;
	}
	return sisa;
}

int greedy(int);
int main(){
	scanf("%d%d%d",&n,&m,&d);
	
	for(int k=0;k<m;k++){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
		edge[k] = make_pair(a,b);
		deg[a]++;deg[b]++;
	}
	
	int bisa = 1;
	rem = d;
	while(bisa){
		bisa = 0;
		for(int k=0;k<n;k++)if(deg[k]>rem){
			if(rem==0)break;
			flag[k] = 1;
			rem--;
			for(int i=0;i<adj[k].size();i++)deg[adj[k][i]]--;
			bisa = 1;
			deg[k] = 0;
			break;
		}
		if(rem<0)break;
	}
	if(rem<0){
		printf("Impossible\n");
		return 0;
	}
	for(int k=0;k<n;k++){
		vector<int> tmp;
		for(int i=0;i<adj[k].size();i++){
			int next = adj[k][i];
			if(flag[next] || flag[k])continue;
			tmp.push_back(next);
		}
		adj[k] = tmp;
		deg[k] = adj[k].size();
	}
	int M = 0;
	for(int k=0;k<m;k++){
		int a = edge[k].first;
		int b = edge[k].second;
		if(flag[a] || flag[b])continue;
		edge[M++] = edge[k];
	}
	m = M;
	if(m>rem*rem){
		printf("Impossible\n");
		return 0;
	}
	//rep(k,0,n)printf("%d ",deg[k]);line;
	int tmp = greedy(rem);
	if(tmp<0)printf("Impossible\n");else printf("%d\n",d-tmp);
	return 0;
}

inline void remove(int a){
	deg[a] = 0;
	rep(k,0,adj[a].size()){
		if(deg[adj[a][k]])deg[adj[a][k]]--;
	}
}
vector<int>rev[3005];
int greedy(int sisa){
	if(sisa<0)return sisa;
	int maks = 0;
	rep(k,0,n)rev[k].clear();
	rep(k,0,n)if(deg[k])rev[deg[k]].pb(k),maks = max(maks,deg[k]);
	
	if(maks==0)return sisa;
	int node;
	if(rev[1].size()){
		node = rev[1][0];
		rep(k,0,adj[node].size())if(deg[adj[node][k]]){
			node = adj[node][k];break;
		}
	}
	else{
		node = rev[maks][0];
	}
	//printf("|%d",node+1);line;
	remove(node);
	return greedy(sisa-1);
}