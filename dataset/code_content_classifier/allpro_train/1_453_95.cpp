#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)
#define REPL(i,a,b) for (ll i = a; i < b; i++)


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// solution comes here
	ll n;cin>>n;
	array<ll, 2> a[n];
	for(ll i=0;i<n;i++){
	    cin>>a[i][1]>>a[i][0];
	}
	sort(a,a+n);
    ll l=0; ll r=n-1;ll p=0;ll ans=0;
    while(l<=r){
        if(a[l][0]<=p){
            p+=a[l][1];
            ans+=a[l][1];
            l++;
        }
        else{
            if(a[r][1]+p<=a[l][0]){
                p+=a[r][1];
                ans+=a[r][1]*2;
                r--;
            }
            else{
                a[r][1]-=(a[l][0]-p);
                ans+=(a[l][0]-p)*2;
                p=a[l][0];
            }
        }
    }
    cout<<ans<<endl;
}