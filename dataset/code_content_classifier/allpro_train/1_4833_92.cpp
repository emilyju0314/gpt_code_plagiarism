#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,k={};
  	cin >> s;
  	for (int i=0;i<s.size();i++){
    	if(s[i]=='0') k=k+'0';
      	if(s[i]=='1') k=k+'1';
      	if(s[i]=='B' && k.size()>=1 ) k.pop_back();
    }
  	cout << k << endl;

}