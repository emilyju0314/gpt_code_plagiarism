#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,x=0,y=0,z=0,ans=0,m,j,tmp;
char s[15];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		m=strlen(s);
		for(j=0;j<m;j++)if(s[j]=='A'&&j+1<m&&s[j+1]=='B')ans++;
		if(s[0]!='B'&&s[m-1]=='A')x++; 
		if(s[0]=='B'&&s[m-1]!='A')y++; 
		if(s[0]=='B'&&s[m-1]=='A')z++; 
	}
	if(z==0)
	{
		ans+=min(x,y);
	}
	else
	{
		ans+=z-1;
		if(x>0)x--,ans++;
		if(y>0)y--,ans++;
		tmp=min(x,y);
		ans+=tmp;
	}
	printf("%d\n",ans);
	return 0;
}