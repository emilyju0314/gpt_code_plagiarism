#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size()-1;++i) if(s[i]==s[i+1]){
		printf("%d %d\n",i+1,i+2);
		return 0;
	}
	for(int i=0;i<s.size()-2;++i) if(s[i]==s[i+2]){
		printf("%d %d\n",i+1,i+3);
		return 0;
	}
	printf("-1 -1\n");
	return 0;
}