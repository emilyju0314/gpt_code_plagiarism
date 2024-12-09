#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int M = 998244353;
const int mod = 1e9+7; 
const int inf = 1e18;
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
 
int power(int x,int y,int p){
	int res = 1;
	x = x % p;
	if(x == 0) return 0;
	while (y > 0){
		if (y & 1) res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
		}
	return res;
}

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
// Returns LCM of array elements 
int flcm(int arr[], int n) 
{ 
    // Initialize result 
    int ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
void solve(){
	int n, u, v;
	cin>>n>>u>>v;
	set<int>s;
	int a[n], max1=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	for(int i=0;i<n-1;i++)
		max1=max(max1, abs(a[i]-a[i+1]));
	if(!max1) cout<<min(u+v, 2*v)<<"\n";
	else if(max1==1) cout<<min(u,v)<<"\n";
	else cout<<"0\n";
}

signed main(){
	fast;
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}
