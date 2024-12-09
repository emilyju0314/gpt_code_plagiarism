#include <bits/stdc++.h>
using namespace std;

string s;
int a, b[3], ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		if(s[i] == 'R'){
			if(a == 3){
				if(b[0] && b[1] && b[2]) ++ans;
				a = 0;
				b[0] = b[1] = b[2] = {};
			}else{
				++a;
				if(!b[a-1]) ++b[a-1];
			}
		}else{
			if(a == 1) b[0] = b[1] = b[2] = {};
			a = (a + 3) % 4;
		}
	}
	cout << ans << "\n";
}
