#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pii pair <int,int>
#define pll pair <ll,ll>
#define testcase() int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define vll vector <ll>
#define vi vector <int>
#define all(v) v.begin(),v.end()

ll M = 1e9 + 7;
double pi = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powerm(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x)%M; y=y>>1; x=(x*x)%M;} return res%M; }
ll power(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x); y=y>>1; x=(x*x);} return res; }
ll gcd(ll a,ll b){if(b>a)return gcd(b,a); if(b==0)return a; return gcd(b,a%b);}

int ask(int t,int i,int j,int x)
{
	cout<<"? "<<t<<' '<<i<<' '<<j<<' '<<x<<endl;
	int p; cin>>p;
	return p;
}

int solve(int n)
{
	int i = 1;
	while(i<=n)
	{
		if( i == n ) return n;
		int p = ask(2,i,i+1,1);
		if( p == 1 ) return i;
		if( p == 2 )
		{
			int q = ask(2,i+1,i,1);
			if( q == 1 ) return i+1;
		}
		i = i+2;
	}
	return n;
}

void solve1(int id,int n)
{
	vi ans(n+1);
	ans[id] = 1;
	forn1(i,n)
	{
		if( i == id ) continue;
		ans[i] = ask(1,id,i,n-1);
	}
	cout<<"!";
	forn1(i,n) cout<<' '<<ans[i];
	cout<<endl;
}

int main() {
	
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	testcase()
	{
		int n; cin>>n;
		int p = solve(n);
		solve1(p,n);

	}

	return 0;
}
