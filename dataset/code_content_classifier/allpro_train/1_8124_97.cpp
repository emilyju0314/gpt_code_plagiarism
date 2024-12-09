#include<bits/stdc++.h>
using namespace std;
bool bn,bw,bs,be;
char s[10001];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len;i++)
	{
		if (s[i]=='N') bn=true;
		if (s[i]=='W') bw=true;
		if (s[i]=='S') bs=true;
		if (s[i]=='E') be=true;
	}
	if (bn==bs&&bw==be) printf("Yes");
	else printf("No");
	return 0;
}