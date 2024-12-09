#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a=0,w=0,t=0,r=0,n;
	scanf("%d",&n);
	while(n--)
	{
		char str[5]={0};
		scanf("%s",str);
		if(str[0]=='A')
			a++;
		else if(str[0]=='W')
			w++;
		else if(str[0]=='T')
			t++;
		else 
			r++;
	}
	printf("AC x %d\nWA x %d\nTLE x %d\nRE x %d",a,w,t,r);
}