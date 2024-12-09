#include<iostream>
#include<cstring>
using namespace std;
char a,c;
int n,tot;
int main()
{
	cin>>n;
	cin>>c;
	for(int i=1;i<n;++i)
	{
		cin>>a;
		if(a!=c)
		{
			tot++;
			c=a;
		}
	}
	cout<<tot+1;
}