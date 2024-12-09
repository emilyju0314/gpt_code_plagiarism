#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void debug(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  debug(comma + 1, args...);
}

const int INF=1000000000+5;
const int N=3e5+5;
const int M=30;
const ll oo=LLONG_MAX;
const int mod=1e9+7;

void solve(){
	string s;
	cin>>s;
	int n=(int)s.size();
	vector<vector<int>> pos(26);
	for(int i=0;i<n;++i){
		int x=s[i]-'a';
		pos[x].push_back(i);
	}
	string ans;
	vector<bool> flag(26);
	int j;
	for(int i=0;i<n;i=j+1){
		j=n;
		for(int k=25;k>=0;--k){
			if(flag[k]) continue;
			if(!(int)pos[k].size()) continue;
			auto it=lower_bound(all(pos[k]),i);
			if(it==pos[k].end()) continue;
			j=*it;
			bool good=1;
			for(int sm=0;sm<k;++sm){
				if(flag[sm]) continue;
				// maximum id of smaller can put in right here
				if((int)pos[sm].size()&&pos[sm].back()<j){
					good=false;
					break;
				}
			}
			if(good) break;
		}
		if(j==n) break;
		ans+=s[j];
		flag[s[j]-'a']=1;
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
