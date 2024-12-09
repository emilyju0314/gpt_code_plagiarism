#include<cstdio>
#include<cstring>
using namespace std;
int Fst[100005][26],cnt[26],ls,lt,zj1,zj2;
long long ans;
char S[100005],T[100005];
int main()
{
	scanf(" %s %s",S+1,T+1);
	ls=strlen(S+1);
	lt=strlen(T+1);
	for(int i=ls;i>=1;i--)
	for(int j=0;j<26;j++)
	Fst[i][j]=(S[i]-'a'==j?i:Fst[i+1][j]);
	for(int i=1;i<=lt;i++)
	if(!Fst[1][T[i]-'a'])
	{
		printf("-1");
		return 0;
	}
	zj1=1;
	while(zj1!=lt+1)
	{
		zj2=0;
		while(Fst[zj2+1][T[zj1]-'a']&&zj1!=lt+1)
		zj2=Fst[zj2+1][T[zj1]-'a'],zj1++;
		if(zj1==lt+1)
		ans+=zj2;
		else
		ans+=ls;
	}
	printf("%lld",ans);
	return 0;
}