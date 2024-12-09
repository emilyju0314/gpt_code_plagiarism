#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   	ll t;
   	cin>>t;
   	while(t--){
        ll n,k,res=1;
        cin>>n>>k;
     	string s;
     	cin>>s;
     
  		ll i = s.find_first_of('*');
  		while(true){
    		ll j = min(n-1, i + k);
    		for (; i < j && s[j] == '.'; j--) {}
    			if (i == j) {
      				break;
    			}
    		res++;
    		i = j;
  		}
  		cout << res << "\n";
	}
return 0;
}