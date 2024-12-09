#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,now=0,ans=0;
	string s;
	cin>>n>>s;
	for(i=0;i<n;i++){
		if(s[i]=='I'){
			now++;
			ans=max(ans,now);
		}
		else now--;
	}
	cout<<ans<<endl;
	return 0;
} 