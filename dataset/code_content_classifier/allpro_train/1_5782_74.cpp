#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	int i;
	for( i=sqrt(n);;i--)
	{
	if(n%i==0)
	break;
	}
	printf("%d\n",(int)log10(n/i)+1);
	return 0;
	
}