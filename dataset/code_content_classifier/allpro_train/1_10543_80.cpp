#include<bits/stdc++.h>
using namespace std;

#define MAXN 305
#define int long long
#define INF (int)0x3f3f3f3f*(int)0x3f3f3f3f

int n,m,l;
int a[MAXN][MAXN];
int f[MAXN][MAXN];

void rd()
{
	cin >> n >> m >> l;
	memset(a,0x3f,sizeof(a));
	for(int i = 1; i <= m; i ++) {
		int x,y,c;
		cin >> x >> y >> c;
		a[x][y] = c;
		a[y][x] = c; 
	}
}

signed main()
{
	rd();
//	cout<<INF<<"\n"<<a[1][1]<<"\n";
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
	memset(f,0x3f,sizeof(f));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(i  != j && a[i][j] <= l) {
				f[i][j] = 1;
			}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	int q;
	cin >> q;
	while(q --)
	{
		int s,t;
		cin >> s >> t;
		if(f[s][t] >= INF) cout<<-1<<"\n";
		else cout<<f[s][t]-1<<"\n";
	}
		
	return 0;
}