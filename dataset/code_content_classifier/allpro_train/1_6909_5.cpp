#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <map>
#include <queue>
#include <string>
using namespace std;

string s;

int main(){
	while(cin>>s){
		int cur=0;
		while(cur<s.size()){
			if(s[cur]!='@'){cout<<s[cur];cur++;}
			else {
				for(int i=0;i<s[cur+1]-'0';i++)cout<<s[cur+2];
				cur+=3;
			}
		}
		cout<<endl;
	}
}