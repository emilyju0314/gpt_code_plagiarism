/* “No one is perfect - that’s why pencils have erasers.” */
 
#include <bits/stdc++.h>
using namespace std;
int M =  1e9 + 7;
 
#define ll long long int
#define endl '\n'
#define sp <<" "<<
#define pb push_back
#define S second
#define F first
#define dbg cout<<"hi";
#define vp vector<pair<long long int ,long long int>>
#define vv vector<vector<long long int>>
#define pii pair<long long int,long long int>
#define vi vector<long long int>
#define mpvp map<p,vector<pii>>
ll power(ll x, ll n) {
      ll u;
      if (n == 0){
            return 1;  
      }
      else if(n%2==0){
            u= power(x,n/2);
            return u=(u*u);
      }
      
      else{
           return x*power(x,n-1); 
      }
}
 
 
ll modpow(ll x, ll n, ll m) {
      ll u;
      if (n == 0){
            return 1%m;  
      }
      else if(n%2==0){
            u= modpow(x,n/2,M);
            return u=(u*u)%m;
      }
      
      else{
           return x*modpow(x,n-1,M); 
      }
}
/*char sam[1000][1000];
ll vis[1000][1000]={0};
mpvp arr;
ll coun=0;
 
 
void  dfs(p node){
      vis[node.F][node.S]=1;
      for(auto child: arr[node]){
            if(vis[child.F][child.S]==0){
                  dfs(child);
            }
      }
      if(coun>0){
            sam[node.F][node.S]='X';
            coun--;
      }
      return;
}*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
      ll t;
      cin>>t;
      while(t--){
            ll n;
            cin>>n;
            ll arr[n];
            for(ll i=0;i<n;i++){
                  cin>>arr[i];
            }
            ll sum=0;
            for(ll i=0;i<n;i++){
                  ll a=arr[i];
                  ll upcominde=(2*(i+1));
                  ll dive=upcominde/arr[i];
                  ll upcomdiv=dive+1;
                  ll finalinde=upcomdiv*arr[i];
                  ll p=finalinde-i-1;
                  for(ll j=p-1;j<n;j+=a){
                        if(arr[i]*arr[j]==i+1+j+1){
                              sum++;
                        }
                  }
            }
            cout<<sum<<endl;
      }
	return 0;
	
}