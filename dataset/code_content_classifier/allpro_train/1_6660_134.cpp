#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define maxn 10000+10
#define maxe maxn*maxn/2+1
int pa[maxn],ran[maxn];

void init(const int& n){
	for(int i=0; i<n; i++){
		pa[i] = i;
		ran[i] = 0;
	}
}

// int find(const int& x){
// 	if(pa[x]==x) return x;
// 	else pa[x] = find(pa[x]);
// }
int find(const int& x)
{
	if (pa[x] == x)
	{
		return x;
	}
	else
	{
		return pa[x] = find(pa[x]);
	}
}

// void unite(int x,int y){
// 	x = find(x); y = find(y);

// 	if(x==y) return;
// 	if(ran[x] < ran[y]){
// 		pa[x] = y;
// 	}else{
// 		pa[y] = x;
// 		if(ran[x] == ran[y])
// 			++ran[x];
// 	}
// }
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
	{
		return;
	}
 
	if (ran[x] < ran[y])
	{
		pa[x] = y;
	}
	else
	{
		pa[y] = x;
		if (ran[x] == ran[y])
		{
			++ran[x];
		}
	}
}

bool same(const int& x,const int& y){
	return find(x) == find(y);
}

struct edge{
	int u,v;
	double cost;
	edge(int u=0,int v=0,double cost=0) : u(u),v(v),cost(cost){}
	bool operator<(const edge& rhs) const{
		return cost > rhs.cost;
	}
};
edge es[maxe];
int V,E;

pair<int,int> pile[maxn];

double kruskal(){
	sort(es,es+E);
	init(V);
	double res = 0;
	for(int i=0; i<E; i++){
		edge e = es[i];
		if(!same(e.u,e.v))
			unite(e.u,e.v);
		else
			res += e.cost;
	}

	return res;
}


int main(){
	scanf("%d%d",&V,&E);
	for(int i=0; i<V; i++)
		scanf("%d%d",&pile[i].first,&pile[i].second);

	for(int i=0; i<E; i++){
		scanf("%d%d",&es[i].u,&es[i].v);
		--es[i].u,--es[i].v;
		int dx = pile[es[i].u].first - pile[es[i].v].first;
		int dy = pile[es[i].u].second - pile[es[i].v].second;
		es[i].cost = sqrt(dx*dx+dy*dy);	
	}

	printf("%.3lf\n",kruskal());
}