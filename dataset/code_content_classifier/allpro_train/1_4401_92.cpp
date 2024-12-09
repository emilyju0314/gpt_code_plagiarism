// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define ll long long
#define reg register
using namespace std;
string s;
int main()
{
	cin>>s;
	puts((s[0]==s[s.length()-1])^(s.length()&1)?"First":"Second");
	return 0;
}