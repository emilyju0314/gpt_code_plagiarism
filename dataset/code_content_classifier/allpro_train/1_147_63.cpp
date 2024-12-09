/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=2000;
const int INF=(int)1e9+5;
int n,k,q,A[MAXN+5],ans=INF;
void SOLVE(int x)
{
	vector<int> pri;
	int i=0;
	while(i<n)
	{
		vector<int> que;
		while(A[i]<x && i<n) i++;
		while(A[i]>=x && i<n) que.push_back(A[i++]);
		if(que.size()>=k)
		{
			sort(que.begin(),que.end());
			for(int j=0;j<(int)que.size()-k+1;j++)
				pri.push_back(que[j]);
		}
	}
	sort(pri.begin(),pri.end());
	if((int)pri.size()>=q)
		ans=min(ans,pri[q-1]-pri[0]);
}
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<n;i++)
		SOLVE(A[i]);
	printf("%d\n",ans);
	return 0;
}
