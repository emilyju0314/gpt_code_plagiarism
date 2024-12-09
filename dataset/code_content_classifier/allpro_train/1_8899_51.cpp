#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<int> edge[100010];
queue<int> q;
int col[100010];
int main()
{
	cin >>n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >>x>>y;
		x--,y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	fill(col,col+n,-1);
	col[0]=1;
	col[n-1]=0;
	q.push(0);
	q.push(n-1);
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		int t=col[x];
		for (int i=0;i<edge[x].size();i++)
		{
			int xi=edge[x][i];
			if (col[xi]==-1) col[xi]=t,q.push(xi);
		}
	}
	int r1=0,r2=0;
	for (int i=0;i<n;i++)
	{
		if (col[i]) r1++;
		else r2++;
	}
	cout <<(r1>r2 ? "Fennec" : "Snuke");
	return 0;
}