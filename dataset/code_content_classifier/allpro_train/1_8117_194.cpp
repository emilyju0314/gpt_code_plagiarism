#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n;
cin >> n;
map<string,int> mp;
ll ans = 0;
for(int i = 0; i < n; i++){
string s; cin >> s;
sort(s.begin(), s.end());
mp[s]++;
if(mp[s]>=2)ans += mp[s]-1;
}
cout << ans << endl;
return 0 ;
}