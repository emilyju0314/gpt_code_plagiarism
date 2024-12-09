#include <bits/stdc++.h>
using namespace std;
const int N=805;
int n,m,k;
char s[N][N];
int d[N][N],qx[N*N],qy[N*N];
int dx[4]={ 0, 0,-1, 1};
int dy[4]={-1, 1, 0, 0};
bool check(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=m&&s[x][y]!='#';
}
int main(){
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(d,0,sizeof d);
	int sx,sy;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='S')
				sx=i,sy=j;
	int head=0,tail=0;
	tail++;
	qx[tail]=sx,qy[tail]=sy;
	d[sx][sy]=1;
	while (head<tail){
		head++;
		int x=qx[head],y=qy[head];
		if (d[x][y]==k+1)
			continue;
		for (int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if (!check(nx,ny)||d[nx][ny])
				continue;
			d[nx][ny]=d[x][y]+1;
			tail++;
			qx[tail]=nx,qy[tail]=ny;
		}
	}
	int ans=23333;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]!='#'&&d[i][j]){
				if (i==1||j==1||i==n||j==m)
					ans=1;
				else {
					ans=min(ans,(i-1+k-1)/k+1);
					ans=min(ans,(j-1+k-1)/k+1);
					ans=min(ans,(n-i+k-1)/k+1);
					ans=min(ans,(m-j+k-1)/k+1);
				}
			}
	cout << ans;
	return 0;
}