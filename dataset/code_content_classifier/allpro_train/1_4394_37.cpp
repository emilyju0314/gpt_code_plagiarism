#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;

    map<char,int> mp;
    mp['r']=p;
    mp['s']=r;
    mp['p']=s;
    int ans=0;
    for(int i=0; i<n; ++i){
        ans += mp[t[i]];
        if(i+k<n && t[i]==t[i+k]) t[i+k]='x';
    }
    cout << ans << endl;
}