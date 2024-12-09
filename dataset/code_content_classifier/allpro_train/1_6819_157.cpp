#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool a[100];
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<n-1;i++){
		int t=0;
		memset(a,0,sizeof(a));
		for(int j=0;j<=i;j++) a[s[j]-'A']=1;
		for(int j=i+1;j<n;j++){
			if(a[s[j]-'A']){
				a[s[j]-'A']=0;
				t++;
			}
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}