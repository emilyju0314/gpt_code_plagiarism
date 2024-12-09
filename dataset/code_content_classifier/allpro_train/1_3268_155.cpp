#include<iostream>
#include<cstdio>
using namespace std;
string s;
int cnt=1,root,lst;
int main(){
	cin>>s;
	if(s[0]=='0'||s[s.length()-1]=='1'){
		puts("-1");
		return 0;
	}
	for(register int i=0;i<(s.length()>>1);i++){
		if(s[i]!=s[s.length()-i-2]){
			puts("-1");
			return 0;
		}
	}
	for(register int i=0;i<s.length();i++){
		if(s[i]=='1'){
			root=cnt;
			printf("%d %d\n",root,++cnt);
			if(lst)for(register int j=1;j<i+1-lst;j++)printf("%d %d\n",root,++cnt);
			lst=i+1;
		}
	}
}