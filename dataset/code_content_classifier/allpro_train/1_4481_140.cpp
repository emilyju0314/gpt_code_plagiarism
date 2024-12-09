#include<iostream>
#include <iomanip>
using namespace std;
int a[1000];
int main()
{
	int n;
	int maxn=0;
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	if(a[i]>maxn)
	maxn=a[i];
	sum+=a[i];
}
if(sum-maxn<=maxn)
cout<<"No";
else
cout<<"Yes";
}