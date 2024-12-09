#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51,MAX_S=51;

int n,ok; string port,code;
vector<string> codes(MAX_N),check(MAX_N);
vector<char> vowels={'a','i','u','e','o'};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(cin >> n,n){
		for (int i=0;i<n;++i){
			cin >> port; code=""; code+=port[0];
			for (int j=0;j+1<port.size();++j){
				for (int k=0;k<5;++k){
					if (port[j]==vowels[k]) code+=port[j+1];
				}
			}
			for(int j=0;j<MAX_S;++j){
				if (j>=code.size()) code+='#';
			}
			codes[i]=code;
		}
		for (int k=1;k<=MAX_S;++k){
			ok=1;
			for (int i=0;i<n;++i) check[i]=codes[i].substr(0,k);
			for (int i=0;i<n;++i){
				for (int j=i+1;j<n;++j){
					if (check[i]==check[j]) ok=0;
				}
			}
			if (ok){
				cout << k << '\n';
				break;
			}
			if (k==MAX_S) cout << -1 << '\n';
		}
	}
}
