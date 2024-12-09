#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long
#define lowbit(x) x&-x
using namespace std;
char s[200010];
int i,j,n,now,l,r,d[30],num,p[200010],q,t[200010],ans;
struct type
{
	int x,y;
}a[200010];
bool cmp(type x,type y)
{
	return max(n-x.x-1,x.y)>max(n-y.x-1,y.y);
}
void add(int x)
{
	for(;x<=n;x+=lowbit(x))t[x]++;
}
int get(int x)
{
	int sum=0;
	for(;x;x-=lowbit(x))sum+=t[x];
	return sum;
}
signed main()
{
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)
		d[s[i]-'a']++;
	for(i=0;i<26;i++)
		if(d[i]&1)q++;
	if(q>(n&1))
	{
		cout<<-1<<endl;
		return 0;
	}
	for(i=0;i<26;i++)
	{
		l=0,r=n-1;
		for(j=1;j<=d[i]/2;j++)
		{
			while(s[l]!='a'+i)l++;
			while(s[r]!='a'+i)r--;
			a[++now].x=l+1;
			a[now].y=r+1;
			l++,r--;
		}
		if(d[i]&1)
		{
			for(j=l;j<r;j++)
				if(s[j]=='a'+i)break;
			p[j+1]=n/2+1;
		}
	}
	sort(a+1,a+n/2+1,cmp);
	for(i=1;i<=n/2;i++)
	{
		p[a[i].x]=i;
		p[a[i].y]=n-i+1;
	}
	for(i=1;i<=n;i++)
	{
		ans+=get(n-p[i]+1);
		add(n-p[i]+1);
	}
	cout<<ans<<endl;
}