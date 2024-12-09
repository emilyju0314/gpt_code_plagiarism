#include<bits/stdc++.h>
using namespace std;
int n,b=0,r=0;
char s[110];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) 
		if (s[i]=='R') r++;
		else b++;
	if (r>b) printf("Yes\n");
	else printf("No\n");
	return 0;
}