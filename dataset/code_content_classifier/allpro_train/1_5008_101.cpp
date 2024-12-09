#include <iostream>
#include <vector>
using namespace std;


namespace{
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >


#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define PB push_back
vector<vint> vv;
vint vis;

int dfs(int a,int b){
	// cout<<a<<endl;
	int ret=0;
	rep(i,vv[a].size()){
		if(vis[vv[a][i]]) continue;
		vis[a]=1;
		int next=vv[a][i];
		ret=max(ret,dfs(next,b));
		vis[a]=0;
	}
	return ret+1;
}
// int solve2(int st){
        // int ret = 0;
        // rep(i,edge[st].size()){
            // int next = edge[st][i];
            // if(visit[next]==0){
                // visit[next]=1;
                // ret = max(solve2(next)+1, ret);
                // visit[next]=0;
            // }
        // }
        // return ret;
    // }
void mainmain(){
	int n;
	while(cin>>n,n){
		// cout<<n<<endl;
		vv=vector<vint>(100);
		vis=vint(100,0);
		rep(i,n){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			// cout<<a<<" "<<b<<endl;
			vv[a].PB(b);
			vv[b].PB(a);
		}
		int ans=0;
		rep(i,100) vis[i]=0;
		rep(i,100){
			// cout<<"i "<<i<<endl;
			int t=dfs(i,0);
			// cout<<i<<" "<<t<<endl;
			ans=max(ans,t);
		}
		cout<<ans<<endl;
	}
}



}
int main() try{
    mainmain();
}
catch(...){
}