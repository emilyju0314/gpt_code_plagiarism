//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#define ll long long
#define inf 20021225
#define N 1000010
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
char ch[N],s[N]; int n;
int pre[N],nxt[N],cnt[3];
set<int> pos[3]; int id[3];
void modify(int x)
{
	if(!x||x>n)	return;
	if(s[pre[x]]==s[nxt[x]])
	{
		if(pos[s[x]-'A'].find(x)!=pos[s[x]-'a'].end())	pos[s[x]-'A'].erase(x);
	}
	else	pos[s[x]-'A'].insert(x);
}
void del(int x)
{
	if(pos[s[x]-'A'].find(x)!=pos[s[x]-'A'].end()) pos[s[x]-'A'].erase(x);
	pre[nxt[x]]=pre[x],nxt[pre[x]]=nxt[x];
	modify(pre[x]); modify(nxt[x]);
}
bool cmp(int x,int y){return cnt[x]<cnt[y];}
int main()
{
	scanf("%s",ch+1); int nn=0; n=strlen(ch+1);
	for(int i=1;i<=n;i++)	if(ch[i]!=ch[i-1])
		s[++nn]=ch[i];
	n=nn; nxt[0]=1; pre[n+1]=n;
	for(int i=1;i<=n;i++)
	{
		cnt[s[i]-'A']++;
		pre[i]=i-1,nxt[i]=i+1;
		if(s[i-1]!=s[i+1])	pos[s[i]-'A'].insert(i);
	}
	int mn=0,mx=0,mid=0;
	id[0]=0,id[1]=1,id[2]=2;
	sort(id,id+3,cmp);
	mn=id[0],mx=id[2],mid=id[1];
	if(cnt[mid]!=cnt[mx])
	{
		while(cnt[mid]!=cnt[mx]&&!pos[mx].empty())
			del(*pos[mx].begin()),cnt[mx]--;
		
		if(cnt[mx]>cnt[mid])
		{
			int p2,p1;
			for(int i=nxt[0];i!=n+1;i=nxt[i])
			{
				p1=pre[i],p2=pre[p1];
				if(p2&&p1&&s[p2]-'A'==mn&&s[p1]-'A'==mx&&s[i]-'A'==mn)
					del(p1),del(p2),cnt[mx]--,cnt[mn]--;
				if(cnt[mx]==cnt[mid])	break;
			}
		}
	}
	if(cnt[mx]!=cnt[mid])	return 0;
	
	if(cnt[mn]!=cnt[mid])
	for(int i=nxt[0];i!=n+1;i=nxt[i])
	{
		int p1=pre[i],p2=pre[p1],n1=nxt[i];
		if(((!p2||s[p2]-'A'!=mn)||(n1==n+1||s[n1]-'A'!=mn))&&(p1&&s[p1]-'A'!=mn)&&s[i]-'A'!=mn)
			del(p1),del(i),cnt[mid]--,cnt[mx]--;
		if(cnt[mn]==cnt[mid])	break;
	}
	if(cnt[mid]==cnt[mn]&&cnt[mn]==cnt[mx])	for(int i=nxt[0];i!=n+1;i=nxt[i])
		printf("%c",s[i]);
	return 0;
}
