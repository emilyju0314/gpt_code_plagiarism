#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b;
	string s;
	cin>>n>>a>>b>>s;
	int jap=0,over=0;
	for(int i=0;i<n;i++)
		if(jap+over<a+b&&s[i]=='a')
			cout<<"Yes"<<endl,jap++;
		else if(jap+over<a+b&&over<b&&s[i]=='b')
			cout<<"Yes"<<endl,over++;
		else
			cout<<"No"<<endl;
}
