#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
const int oo=1073741819;
using namespace std;
struct point{
	int x,y,A,B,D;
}G[2005];
int f[205][105][105],g[105][105][3],b[105][105],d[205][105][105];
int n,m,s,t,F;
inline void Up(int &x,int y)
{
	if (x>y) x=y;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&s,&t,&F);
	s++,t++;
	int id=0;
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d%d%d",&G[i].x,&G[i].y,&G[i].A,&G[i].B,&G[i].D);
		G[i].x++,G[i].y++;
		if (G[i].A<G[i].B) id=i;
	}
	for (int P=1;P<=F;P++) {
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) 
				if (i!=j) f[P][i][j]=d[P][i][j]=oo;else f[P][i][j]=d[P][i][j]=0;
		for (int i=1;i<=m;i++) {
			if (G[i].A<G[i].B) continue;
			int x=G[i].x,y=G[i].y;
			if (P>G[i].D) Up(f[P][x][y],G[i].A*G[i].D+G[i].B*(P-G[i].D));
			else Up(f[P][x][y],P*G[i].A);
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				if (f[P][i][k]<oo)
					for (int j=1;j<=n;j++)
						if (f[P][k][j]<oo)
							Up(f[P][i][j],f[P][i][k]+f[P][k][j]);
	}
	if (id)
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int p=0;p<=F;p++) {
				int cos=0;
				if (p>G[id].D) cos=G[id].A*G[id].D+G[id].B*(p-G[id].D);
				else cos=G[id].A*p;
				if (f[F-p][i][j]<oo && f[p][i][G[id].x]<oo && f[p][G[id].y][j]<oo)
					Up(d[F][i][j],f[F-p][i][j]+f[p][i][G[id].x]+cos+f[p][G[id].y][j]);
			}
	int ans=min(f[F][s][t],d[F][s][t]);
	//cout<<f[F][s][s]<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (f[F][s][i]<oo && d[F][i][j]<oo && f[F][j][t]<oo)
				Up(ans,f[F][s][i]+d[F][i][j]+f[F][j][t]);
	if (ans<oo) printf("%d\n",ans);
	else printf("Impossible\n");
	return 0;
}