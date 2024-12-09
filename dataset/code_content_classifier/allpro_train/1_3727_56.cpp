#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>

#define PI 3.14159265359

#define INF 999999;

#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)

typedef long long ll;

using namespace std;



/*
class LightSwitchingPuzzle
{
public:
	int minFlips(string s)
	{

	}
}
*/



int V, E;
vector<int> G[10000];
vector<int> rG[10000];
vector<int> vs;
bool used[10000];
int cmp[10000];


void add_edge(int from, int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v] = true;
	for (int i=0; i<G[v].size(); i++)
	{
		if (!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v, int k)
{
	used[v] = true;
	cmp[v] = k;
	for (int i=0; i<rG[v].size(); i++)
	{
		if (!used[rG[v][i]]) rdfs(rG[v][i], k);
	}
}

int main()
{
	cin >> V >> E;
	
	REP(E)
	{
		int s, t;
		cin >> s >> t;
		add_edge(s, t);
	}
	
	
	//memset(used, 0, sizeof(used));
	REP(10000) used[i] = false;
	vs.clear();
	for (int v=0; v<V; v++)
	{
		if (!used[v]) dfs(v);
	}
	//memset(used, 0, sizeof(used));
	REP(10000) used[i] = false;
	int k = 0;
	for (int i=vs.size()-1; i>=0; i--)
	{
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	
	int Q;
	
	cin >> Q;
	REP(Q)
	{
		int u, v;
		cin >> u >> v;
		if (cmp[u] == cmp[v])
		{
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	
	return 0;
}