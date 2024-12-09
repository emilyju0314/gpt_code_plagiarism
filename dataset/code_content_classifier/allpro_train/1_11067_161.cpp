#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define pl pair<ll,ll>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,b) for(ll i=0;i<b;i++)
#define RFOR(i,a,b) for(ll i=b-1;i>=a;i--)
#define rsort(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(),(v).end()
using namespace std;
ll mod=1000000007;

signed main(){
 ll n,s,sum,ans=0,ans2=0;
 cin>>n;
 vl a(n);
 rep(i,n)cin>>a[i];

 sum = 0,s=1;
 rep(i,n){
     s*=-1;
     sum += a[i];
     if(sum * s <= 0)ans+=abs(sum-s),sum=s;
 }
 sum = 0,s=-1;
 rep(i,n){
     s*=-1;
     sum += a[i];
     if(sum * s <= 0)ans2+=abs(sum-s),sum=s;
 }
    cout << min(ans, ans2) << endl;
}