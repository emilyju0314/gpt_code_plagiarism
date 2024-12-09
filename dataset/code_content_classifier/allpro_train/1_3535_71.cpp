#include <bits/stdc++.h>
using namespace std;
int len[250];
int main()
{
	int n,sum=0;
	cin >>n;
	for (int i=1;i<=2*n;i++)
	cin >>len[i];
	sort(len+1,len+n*2+1);
	for (int i=1;i<=n;i++)
	sum=sum+len[2*i-1];
	cout<<sum;
}