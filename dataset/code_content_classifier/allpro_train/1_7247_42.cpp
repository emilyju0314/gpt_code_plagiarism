#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=105;
typedef long long ll;
int n,m,a[maxn],b[maxn],len;
int c[maxn];
string s[maxn];
int tt;
vector<pair<int,int> > adj[maxn*25];
inline bool chk1(string t){
	if (t.size()==0) return true;
	int l=0,r=(int)t.size()-1;
	while(l<=r){
		if (t[l]!=t[r]) return false;
		l++,r--;
	}
	return true;
}
struct node{
	int id;
	ll val;
	bool operator<(const node &n1)const{
		return val>n1.val;
	}
	node(int id=0,ll val=0):id(id),val(val){}
};
priority_queue<node> q;
ll d[maxn*25];
int vis[maxn*25];
int id[maxn][25];
ll ans=1e16;
inline void diji(){
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first;
			int w=adj[u][i].second;
			if (d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push(node(v,d[v]));
			}
		}
	}
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		string s1;
		int x;
		cin>>s1>>x;
		if (chk1(s1)){
			ans=min(ans,(ll)x);
			continue;
		}
		len++;
		b[len]=s1.size();
		s[len]=" "+s1;
		c[len]=x;
	}
	n=len;
	for (int i=n+1;i<=n*2;i++){
		s[i]=s[i-n];
		c[i]=c[i-n];
		b[i]=b[i-n];
		int l=1,r=b[i];
		while(l<=r){
			swap(s[i][l],s[i][r]);
			l++,r--;
		}
	}
	for (int i=1;i<=n*2;i++){
		for (int j=0;j<=b[i];j++){
			id[i][j]=++tt;
		}
	}
	for (int i=1;i<=n*2;i++){
		for (int j=0;j<=b[i];j++){
			if (j==b[i]) continue;
			int l,r;
			if (i<=n){
				l=n+1,r=n*2;
			}
			else{
				l=1,r=n;
			}
			for (int k=l;k<=r;k++){
				int p1=j,p2=0;
				while(p1+1<=b[i]&&p2+1<=b[k]&&s[i][p1+1]==s[k][p2+1]){
					p1++;
					p2++;
				}
				if (p1==b[i]&&p2==b[k]){
					adj[id[i][j]].push_back(make_pair(id[i][b[i]],c[k]));
					adj[id[i][j]].push_back(make_pair(id[k][b[k]],c[k]));
					continue;
				}
				if (p1==b[i]){
					adj[id[i][j]].push_back(make_pair(id[k][p2],c[k]));
					continue;
				}
				if (p2==b[k]){
					adj[id[i][j]].push_back(make_pair(id[i][p1],c[k]));
					continue;
				}
			}
		}
	}
	memset(d,0x3f,sizeof(d));
	for (int i=1;i<=n*2;i++){
		d[id[i][0]]=c[i];
		q.push(node(id[i][0],d[id[i][0]]));
	}
	diji();
	for (int i=1;i<=n*2;i++){
		for (int j=1;j<=b[i];j++){
			string t="";
			for (int k=j+1;k<=b[i];k++){
				t.push_back(s[i][k]);
			}
			if (chk1(t)){
				ans=min(ans,d[id[i][j]]);
			}
		}
	}
	if (ans>=1e16){
		cout<<"-1"<<endl;
	}
	else cout<<ans<<endl;
}