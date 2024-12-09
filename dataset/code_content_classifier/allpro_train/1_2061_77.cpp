#include<bits/stdc++.h>
using namespace std;
char s1[100],s2[100];
int l1,l2;
inline void sc(int x)
{
	for (int i=1;i<x;++i)
		putchar(s1[i]=='?'?'a':s1[i]);
	for (int i=1;i<=l2;++i)
		putchar(s2[i]);
	for (int i=x+l2;i<=l1;++i)
		putchar(s1[i]=='?'?'a':s1[i]);
	exit(0);
}
inline int check(int x)
{
	for (int i=1;i<=l2;++i)
		if (s1[i+x-1]!='?'&&s1[i+x-1]!=s2[i])
			return 0;
	return 1;
}
int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	l1=strlen(s1+1);
	l2=strlen(s2+1);
	for (int i=l1-l2+1;i;--i)
		if (check(i))
			sc(i);
	puts("UNRESTORABLE");
}