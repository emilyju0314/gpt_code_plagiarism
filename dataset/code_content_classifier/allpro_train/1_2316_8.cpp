#include<cstdio>
#include<set>
using namespace std;
int D;
int c[26];
int S[365][26];
int t[365];
set<int>id[26];
int main()
{
	scanf("%d",&D);
	for(int i=0;i<26;i++)
	{
		scanf("%d",&c[i]);
		id[i].insert(-1);
	}
	for(int i=0;i<D;i++)for(int j=0;j<26;j++)scanf("%d",&S[i][j]);
	int ans=0;
	for(int i=0;i<D;i++)
	{
		scanf("%d",&t[i]);
		t[i]--;
		ans+=S[i][t[i]];
		id[t[i]].insert(i);
		for(int j=0;j<26;j++)ans-=c[j]*(i-*id[j].rbegin());
	}
	for(int i=0;i<26;i++)id[i].insert(D);
	int M;scanf("%d",&M);
	for(;M--;)
	{
		int d,q;scanf("%d%d",&d,&q);d--,q--;
		ans-=S[d][t[d]];
		ans+=S[d][q];
		set<int>::iterator it=id[t[d]].lower_bound(d);
		it=id[t[d]].erase(it);
		{
			int r=*it;
			int l=*--it;
			ans-=c[t[d]]*(r-d)*(d-l);
		}
		it=id[q].lower_bound(d);
		{
			int r=*it;
			int l=*--it;
			ans+=c[q]*(r-d)*(d-l);
		}
		it++;
		id[q].insert(it,d);
		t[d]=q;
		printf("%d\n",ans);
	}
}