/* 
        __ __   _                    __                            __ 
       | || |  (_)                  | |                           | |
 _   _ | || |_  _  _ __ ___    __ _ | |_   ___       _ __    __ _ | |
| | | || || __|| || '_ ` _ \  / _` || __| / _ \     | '_ \  / _` || |
| |_| || || |_ | || | | | | || (_| || |_ |  __/ ___ | |_) || (_| || |
 \__,_||_| \__||_||_| |_| |_| \__,_| \__| \___||___|| |__/ \__,_| |_|
                                                    | |              
                                                    |_|                   
+++++++++++++++++++++++I WISH I COULD HACK TIME++++++++++++++++++++++++
*/

#include<bits/stdc++.h>
using namespace std;
#define ultimate ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define ld long double
#define vll vector <long long>
#define pb push_back
#define test long long tcse;cin>>tcse;while(tcse--)
#define f(start,from,to) for(start=from;start<to;start++)
#define el '\n'
#define max_val 9223372036854775807
#define min_val -9223372036854775808
#define pll pair<long long,long long>
#define vsort(vect) sort(vect.begin(),vect.end())

vector<pll> v;
list<ll> gr[100001];
ll dp[100001][2];

void calculate(ll u, ll p)
{
   for(auto x:gr[u])
   {
      if(x!=p)
	  {
	     calculate(x,u);
		 dp[u][0]+=max(abs(v[u-1].first-v[x-1].first)+dp[x][0],abs(v[u-1].first-v[x-1].second)+dp[x][1]);
		 dp[u][1]+=max(abs(v[u-1].second-v[x-1].first)+dp[x][0],abs(v[u-1].second-v[x-1].second)+dp[x][1]);	
	  }	
   }	
}

int32_t main()
{
ultimate;
test
{
	ll i,n,x,y; cin>>n;
	v.clear();
	f(i,1,n+1)
	{
		gr[i].clear();
		dp[i][0]=dp[i][1]=0;
	}
	//v.push_back({0,0});
	f(i,1,n+1)
	{
		cin>>x>>y;
		v.push_back({x,y});
	}
	f(i,0,n-1)
	{
		cin>>x>>y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	calculate(1,0);
	cout<<max(dp[1][0],dp[1][1])<<el;
}
}