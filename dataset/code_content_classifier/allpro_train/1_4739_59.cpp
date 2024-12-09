#include <cstdio>
#include <cstring>
#include <algorithm>

int n,m,f[101][101];
bool map[101][101];
bool get(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return (ch=='#');
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			map[i][j]=get();
	memset(f,0x7f7f7f7f,sizeof f);
	f[0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			f[i][j]=std::min(f[i][j-1]+(map[i][j]&&!map[i][j-1]),f[i-1][j]+(map[i][j]&&!map[i-1][j]));
		}
	printf("%d\n",f[n][m]);
}