#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<bitset>
#define pa pair<int,int>
#define INF 0x3f3f3f3f
#define inf 0x3f
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

inline ll read()
{
    long long f=1,sum=0;
    char c=getchar();
    while (c<'0' || c>'9')
    {
        if (c=='-')	f=-1;
        c=getchar();
    }
    while (c>='0' && c<='9')
    {
        sum=sum*10+c-'0';
        c=getchar();
    }
    return sum*f;
}
const int MAXN=2010;
const int MAXLEN=10010;
string s[MAXN];
bitset <MAXLEN> f[MAXN];
pa pos[2][1000010];
int num[MAXN]; 
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
		for (int j=0;j<(int)s[i].size();j++)
			num[s[i][j]-'a']++;
	}
	int t=0;
	char p;
	for (int i=0;i<26;i++)
		if (num[i])
			t++,p=i+'a';
	if (t==1)
	{
		cout<<string(k,p);
		return 0;
	}
	f[n][0]=1;
	for (int i=n;i>=1;i--)
		f[i-1]=f[i]|(f[i]<<s[i-1].length());
	string ans;
	int now=0,cnt=0;
	for (int i=0;i<n;i++)
		if (f[i+1][k-(int)s[i].size()])
			pos[now][cnt++]=mp(i,0);
	for (int i=0;i<k;i++)
	{
		char minn='z';
		cnt=min(cnt,10000);
		for (int j=0;j<cnt;j++)
		{
			int id=pos[now][j].fi;
			int ppos=pos[now][j].se;
			minn=min(minn,s[id][ppos]);
		}
		ans.push_back(minn);
		int ncnt=0,m=INF;
		for (int j=0;j<cnt;j++)
		{
			int id=pos[now][j].fi;
			int ppos=pos[now][j].se;
			if (s[id][ppos]!=minn) continue;
			if (ppos+1!=(int)s[id].size())
				pos[now^1][ncnt++]=mp(id,ppos+1);
			else
				m=min(m,id+1);
		}
		for (int j=m;j<n;j++)
			if (k-i-1-(int)s[j].size()>=0 && f[j+1][k-i-1-(int)s[j].size()])
				pos[now^1][ncnt++]=mp(j,0);
		cnt=ncnt;
		now^=1;
	}
	cout<<ans;
    return 0;
}
