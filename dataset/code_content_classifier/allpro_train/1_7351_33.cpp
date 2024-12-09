#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void dump(vector<int> &v){
	for(int i=0;i<v.size();i++){
		cout << v[i] << ' ';
	}
	cout << endl;
}
int n,k,s;
int x[2010],y[2010],z[2010];
int c[2010][2010];
struct edge{
	int to,cost;
	edge(){}
	edge(int to,int cost):to(to),cost(cost){}
};
bool used[2010];
vector<edge> g[2010];
int lap(int *w,int a,int b){
	int d = abs(w[a]-w[b]);
	if(d<s)return s-d;
	else return -1;
}
int f(int a,int b){
	int X = lap(x,a,b);
	int Y = lap(y,a,b);
	int Z= lap(z,a,b);
	if(X==-1||Y==-1||Z==-1)return 0;
	return 2*X*Y+2*Y*Z+2*Z*X;
}
vector<int> path;
void dfs(int v,int p){
	used[v]=true;
	path.pb(v);
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i].to;
		if(u==p)continue;
		if(!used[u])dfs(u,v);
	}
}
int sol_sub_path(){
	int s = 0;
	int t = 0;
	int res = 0;
	int cur = 0;
	int ps = path.size();
	if(k==1)return 0;
	if(ps<k)return -1;
	else{
		for(int i=0;i<(k-1);i++){
			cur += c[path[i]][path[i+1]];
		}
		res = cur;
		for(int i=0;i<ps-k;i++){
			cur -= c[path[i]][path[i+1]];
			cur += c[path[i+k-1]][path[(i+k)]];
			res = max(res,cur);
		}
	}
	return res;
}
int sol_sub_loop(){
	int s = 0;
	int t = 0;
	int res = 0;
	int cur = 0;
	int ps = path.size();
	if(k==1)return 0;
	if(ps<k)return -1;
	else if(ps==k){
		for(int i=0;i<ps;i++){
			res += c[path[i]][path[(i+1)%ps]];
		}
		return res;
	}else{
		/*while(t<path.size()){
			while(t<path.size()&&t-s+1<k){
				cur += c[path[t]][path[(t+1)%ps]];
				t++;
			}
			//cout << s << ' ' << t << ' ' << cur << endl;
			if(t-s+1<k)return res;
			res = max(res,cur);
			cur -= c[path[s]][path[s+1]];
			s++;
		}*/
		for(int i=0;i<(k-1);i++){
			cur += c[path[i]][path[i+1]];
		}
		res = cur;
		for(int i=0;i<ps;i++){
			cur -= c[path[i]][path[(i+1)%ps]];
			cur += c[path[(i+k-1)%ps]][path[(i+k)%ps]];
			res = max(res,cur);
		}
	}
	return res;
}
bool solve(){
	scanf("%d %d %d",&n,&k,&s);
	if(n==0&&k==0&&s==0)return false;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<n;i++)g[i].clear();
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			c[i][j] = c[j][i] = f(i,j);
			if(c[i][j]!=0){
				g[i].pb(edge(j,c[i][j]));
				g[j].pb(edge(i,c[i][j]));
			}
		}
	}
	/*for(int i=0;i<n;i++){
		cout << i << ": ";
		for(int j=0;j<g[i].size();i++){
			cout << g[i][j].to << ' ';
		}
		cout << endl;
	}*/
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}*/
	int ans = -1;
	for(int i=0;i<n;i++){
		if(!used[i]&&g[i].size()==1){
			used[i]=true;
			path.clear();
			dfs(i,-1);
			//dump(path);
			int res = sol_sub_path();
			//cout << res << endl;
			ans = max(ans,res);
		}
	}
	for(int i=0;i<n;i++){
		if(!used[i]){
			used[i]=true;
			path.clear();
			dfs(i,-1);
			//dump(path);
			int res = sol_sub_loop();
			//cout << res << endl;
			ans = max(ans,res);
		}
	}
	if(ans==-1)printf("-1\n");
	else printf("%d\n",s*s*6*k-ans);
	return true;
}
int main() {
	while (solve());
	return 0;
}
