#include<bits/stdc++.h>
using namespace std;
int a;char c;
int main()
{
	cin>>a;
	while(cin>>c)
	{cout<<char((int(c)%65+a)%26+65);}
	return 0;
}