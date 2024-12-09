#include<bits/stdc++.h>
using namespace std;
string s,s1="AKIHABARA";
int e;
int main(){
	cin>>s;
	if(s.size()-1>8){
		printf("NO");
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]==s1[e])e++;
		else{
			if(s1[e]=='A'){
				e++;
				i--;
			}
			else{
				printf("NO");
				return 0;
			}
		}
	}
	if(e<=7){
		printf("NO\n");
	}
	else printf("YES\n");
	return 0;
}