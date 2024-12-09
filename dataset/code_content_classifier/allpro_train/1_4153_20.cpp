#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct DFA{
	int Q;//state
	int A; //alphabet
	vector<vector<int> > t;
	int q0;
	vector<int> F;
	DFA(){}
	DFA(int Q,int A,vector<vector<int> > t,int q0,vector<int> F):Q(Q),A(A),t(t),q0(q0),F(F){}
};

struct NFA{
	int Q;
	int A;
	vector<vector<vector<int> > > t;
	int q0;
	vector<int> F;
	NFA(int Q,int A,vector<vector<vector<int> > > t,int q0,vector<int> F): Q(Q),A(A),t(t),q0(q0),F(F){}
	DFA NFAtoDFA(){
		int DN=1;
		vector<vector<int> > dt(1,vector<int>(A,0));
		vector<int> DF;
		map<vector<int>, int> mp; //sets->id
		queue<vector<int> > que;
		que.push(vector<int>{q0});
		mp[vector<int>{q0}]=0;
		while(que.size()){
			vector<int> vc=que.front();
			que.pop();
			bool flag=false;
			for(int i=0;i<F.size();i++){
				for(int j=0;j<vc.size();j++){
					if(F[i]==vc[j])flag=true;
				}
			}
			if(flag){
				DF.push_back(mp[vc]);
			}
			for(int i=0;i<A;i++){
				vector<int> nvc;
				for(int j=0;j<vc.size();j++){
					for(int k=0;k<t[vc[j]][i].size();k++){
						nvc.push_back(t[vc[j]][i][k]);
					}
				}
				sort(nvc.begin(),nvc.end());
				nvc.erase(unique(nvc.begin(),nvc.end()),nvc.end());
				if(!mp.count(nvc)){
					mp[nvc]=DN++;
					dt.push_back(vector<int>(A,0));
					que.push(nvc);
				}
				dt[mp[vc]][i]=mp[nvc];
			}
		}
		return DFA(mp.size(),A,dt,0,DF);
	}
};

int n;
int a[6],b[6];
ll dp[1005];
bool visited[1005];
vector<int> vc;
DFA M;

void dfs(int v){
	visited[v]=true;
	for(int i=0;i<10;i++){
		if(!visited[M.t[v][i]]){
			dfs(M.t[v][i]);
		}
	}
	vc.push_back(v);
}

void solve(){
	int Q=4*n+1;
	int A=10,q0=0;
	vector<int> F;
	F.push_back(4*n);
	vector<vector<vector<int> > > t(Q,vector<vector<int> >(A,vector<int>{}));
	for(int i=0;i<n;i++){
		int x=a[i]/10;
		int y=b[i]/10;
		for(int j=0;j<10;j++){
			if(a[i]<=j && j<=b[i]){
				t[4*i][j].push_back(4*i+4);
			}
		}
		if(x>0){
			t[4*i][x].push_back(4*i+1);
			for(int j=0;j<10;j++){
				if(a[i]<=x*10+j &&x*10+j<=b[i]){
					t[4*i+1][j].push_back(4*i+4);
				}
			}
		}
		if(x+1<y){
			for(int j=x+1;j<y;j++){
				t[4*i][j].push_back(4*i+2);
			}
			for(int j=0;j<10;j++){
				t[4*i+2][j].push_back(4*i+4);
			}
		}
		if(x<y){
			t[4*i][y].push_back(4*i+3);
			for(int j=0;j<10;j++){
				if(a[i]<=y*10+j&& y*10+j<=b[i]){
					t[4*i+3][j].push_back(4*i+4);
				}
			}
		}
	}
	M=NFA(Q,A,t,q0,F).NFAtoDFA();
	queue<int> que;
	n=M.Q;
	for(int i=0;i<n;i++){
		dp[i]=0;
		visited[i]=false;
	}
	dp[M.q0]=1;
	vc.clear();
	dfs(M.q0);
	reverse(vc.begin(),vc.end());
	for(int i=0;i<vc.size();i++){
		for(int j=0;j<10;j++){
			dp[M.t[vc[i]][j]]+=dp[vc[i]];
		}
	}
	ll ans=0;
	for(int i=0;i<M.F.size();i++){
		ans+=dp[M.F[i]];
	}
	printf("%lld\n",ans);
}

int main(void){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		solve();
		
	}
	
	return 0;
} 
