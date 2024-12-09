#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long ll;

bool ok=0;
string s,t,r;

void solve(){
	int pos=0;
	for(int i=0;i<t.size();i++){
		if(pos==r.size())break;
		if(t[i]==r[pos]){
			pos++;
		}
	}
	if(pos==r.size())ok=true;
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> s >> t;
	r="";
	for(int i=0;i<s.size();i+=2){
		r+=s[i];
	}
	solve();
	r="";
	for(int i=1;i<s.size();i+=2){
		r+=s[i];
	}
	solve();
	if(ok){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}
