#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,int>mp;
int n,m,ans;
string s[1000];
int main()
{
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		mp[s[i]]++;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		cin>>s[0];
		mp[s[0]]--;
	}
	for(int i=1;i<=n;i++)
		ans=max(mp[s[i]],ans);
	printf("%d",ans);
	return 0;
}