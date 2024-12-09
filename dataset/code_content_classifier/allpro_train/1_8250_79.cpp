#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define mod 1000000007
#define  mp make_pair
#define all(x) (x).begin(),(x).end()
#define clrz(x,y,z) (x).clear(),(x).resize((y),(z)) 
#define clr(x,y) (x).clear(),(x).resize(y) 

typedef long long int lli;
typedef vector<lli> vli;
typedef vector<int> vi;
typedef tuple<int,int,long long int>tup;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<lli,lli> pll;
typedef pair<int,int> pii;
 
#define PI 3.1415926535897932384626 
#define deb(x) cout << #x << " = " << x << endl;
#define show(x) {for( auto i : x) cout << i << '\t'; cout << endl;}
#define show2(x,l1,l2) {for( int i=0;i<l1;i++){for(int j=0;j<l2;j++) cout << x[i][j] << '\t'; cout << endl;}}
#define f(i,n) for(int i=0;i<(n);i++)
#define rf(i,n) for(int i=(n-1);i>=0;i--)

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
lli power(lli x, lli y, long long int m = mod) { lli ans = 1; x %= m; while (y) {if (y & 1)ans = (x * ans) % m; x = (x * x) % m; y >>= 1;} return ans;}
 

// int dx[] = {1,-1,0,0};
// int dy[] = {0,0,1,-1};

vector<vi>adj;
vector<bool>visited;
void dfs(int c,vector<int>&dep,vector<int>&ans){
    visited[c]=true;
    ans[c]=dep[c];
    for(int i=0;i<adj[c].size();i++){
        int nxt =adj[c][i];


        if(!(visited[nxt]) && dep[nxt]>dep[c]){
            dfs(nxt,dep,ans);
        }
        if(dep[nxt]<=dep[c]){
            ans[c]=min(ans[c],dep[nxt]);
        }
        else
            ans[c]=min(ans[c],ans[nxt]);

    }

}

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int z=1;
    cin>>z;

    while(z--){
        int n,m;
        cin>>n>>m;
        clr(adj,n);
        clrz(visited,n,false);

        f(i,m){
            int x,y;
            cin>>x>>y;
            x--,y--;
            adj[x].pb(y);
        }

        queue<int>q;
        q.push(0);
        int lvl=1;
        vi dep(n,-1),ans(n);
        dep[0]=0;
        while(!q.empty()){
            int sz= q.size();
            for(int i=0;i<sz;i++){
                int cur=q.front();
                q.pop();
                for(int nxt:adj[cur]){
                    if(dep[nxt]==-1){
                        q.push(nxt);
                        dep[nxt]=lvl;
                    }
                    
                }
            }
            lvl++;
        }
        dfs(0,dep,ans);
        f(i,n)cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
        
}
