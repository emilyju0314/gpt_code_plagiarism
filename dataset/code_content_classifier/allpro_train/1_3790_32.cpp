#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll ans,x;
bool y;
int main(){
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(y){
			if(s[i]=='A')x=1;
			if(s[i]=='B')x=0;
			if(s[i]=='C')ans+=x;
			y=false;
		}
		else{
			if(s[i]=='A')x++;
			if(s[i]=='B')y=true;
			if(s[i]=='C')x=0;
		}
	}
	cout << ans;
	return 0;
}