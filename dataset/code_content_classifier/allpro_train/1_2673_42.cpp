#include<iostream>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,m[6],k[6][4]={0,1,5,4,0,3,5,2,0,2,5,3,0,4,5,1,1,2,4,3,1,3,4,2};
char r[6]={'N','E','W','S','R','L'};
int main(){
	while(true){
		cin>>n;
		if(!n)break;
		rep(i,6)m[i]=i+1;
		int ans=1,t,e;
		string s;
		rep(i,n){
			cin>>s;
			rep(j,6)if(r[j]==s[0])e=j;
			t=m[k[e][0]];
			rep(j,3)m[k[e][j]]=m[k[e][j+1]];
			m[k[e][3]]=t;
			ans+=m[0];
		}
		cout<<ans<<endl;
	}
	return 0;
}