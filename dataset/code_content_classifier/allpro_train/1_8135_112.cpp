#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
int main(){
	char data[53];
	for(int i=0;i<26;i++){
		data[i]='A'+i;data[i+26]='a'+i;
	}
	int n,k;
	string s;
	while(cin>>n,n){
		int k[100];
		for(int i=0;i<n;i++)cin>>k[i];
		cin>>s;
		int a[100];
		for(int i=0;i<s.size();i++){
			if(s[i]>='a')a[i]=26+(s[i]-'a');
			else a[i]=s[i]-'A';
			int t=a[i]-k[i%n];
			if(t<0)t+=52;
			cout<<data[t];
		}
		cout<<endl;
	}
}