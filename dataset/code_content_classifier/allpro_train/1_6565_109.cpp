#include<iostream>
#include<set>
#include<queue>
using namespace std;

struct edge
{
	int to,color;
};

vector<edge> w[100010];
int n,m,d[100010];
set<int> s[100010];

int main()
{
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		w[a].push_back({b,c});
		w[b].push_back({a,c});
	}
	d[1]=0;
	for(int i=2; i<=n; i++)
	d[i]=0x3f3f3f3f;
	priority_queue<pair<int,int>> q;
	q.push({-d[1],1});
	while(q.size())
	{
		int now=q.top().second,cost=-q.top().first;
		q.pop();
		if(d[now]<cost) 
		continue;
		for(edge j:w[now])
		{
			int dist=d[now];
			if(!s[now].count(j.color)) 
			dist++;
			if(dist<d[j.to])
			{
				d[j.to]=dist;
				s[j.to].clear();
				s[j.to].insert(j.color);
				q.push({-d[j.to],j.to});
			}
			else if(dist==d[j.to])
			s[j.to].insert(j.color);
		}
	}
	if(d[n]>4e5)cout<<-1<<endl;
	else cout<<d[n]<<endl;
	return 0;
}
