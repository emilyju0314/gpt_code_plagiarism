
#include<bits/stdc++.h>
using namespace std;
int  main()
{
	string s;
	int n;
	cin>>n>>s;
	if(n&1)
	{
		cout<<"No";
		return 0;
	}
	string t=s.substr(0,n/2);
	t=t+t;
	if(t==s)
		cout<<"Yes";
	else
		cout<<"No";
return 0;
}