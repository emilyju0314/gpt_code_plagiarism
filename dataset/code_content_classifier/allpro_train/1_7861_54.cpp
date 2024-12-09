#include<iostream>
#include<vector>
using namespace std;
int main(){
	string s;cin>>s;
	vector<int> a(4);
	for(int i=0;i<4;i++){
		a[i]=s[i]-'0';
	}
	for(int S=0;S<8;S++){
		int ans=a[0];
		for(int i=0;i<3;i++)if(S>>i & 1)ans+=a[i+1];else ans-=a[i+1];
		if(ans==7){
			string s="0-0-0-0=7";
			for(int i=0;i<4;i++)s[i*2]+=a[i];
			for(int i=0;i<3;i++)if(S>>i & 1)s[i*2+1]='+';
			cout<<s<<endl;
			return 0; 
		}
	}
}