#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s,t;
int main(void){
	cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	reverse(t.begin(), t.end());
	if(s<t)cout<<"Yes";
	else cout<<"No";
}