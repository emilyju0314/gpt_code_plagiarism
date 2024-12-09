#include<iostream>
#include<string>
using namespace std;
 
int main(){
	int n, l = 0, r = 0;
	string s[10000],t;
	cin >> n;
	for(int i=0;i<n;i++) cin >> s[i];
	cin >> t;
	for(int i=0;i<n;i++){
		string x,y;
		x = y = s[i];
		for(int j=0;j<x.length();j++) if(x[j]=='?') x[j] = 'a';
		for(int j=0;j<y.length();j++) if(y[j]=='?') y[j] = 'z';
		if(t<x) r++;
		else if(y<t) l++;
	}
	for(int i=l+1;i<=n-r+1;i++){
		if(i==n-r+1) cout << i << endl;
		else cout << i << ' ';
	}
}