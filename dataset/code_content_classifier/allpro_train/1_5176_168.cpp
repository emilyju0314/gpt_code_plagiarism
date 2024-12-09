#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[10];
	scanf("%s",s);
	for (int i=0;i<strlen(s)-1;i++)
	{
		if (s[i]=='A' && s[i+1]=='C')
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}