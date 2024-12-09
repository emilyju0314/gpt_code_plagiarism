#include<bits/stdc++.h>
#define M 1000000007
#define ll long long 
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
 
ll pw(ll a,ll b){
    if(b==0)return 1;
    if(b%2==1)return (a*pw(a*a,b/2));
    else return (1*pw(a*a,b/2));
}
void solve(){
    ll x,y;
 cin>>x>>y;
 cout<<x-1<<" "<<y<<"\n";
}
 
int main(){	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt" , "w" , stdout);
   	#endif
	fastio;
	ll t=1;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}