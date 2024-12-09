#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x,s;
	cin>>n>>m;
	x=m-n;
	s=x*(x+1)/2;
	cout<<s-m<<endl;
	return 0;
}