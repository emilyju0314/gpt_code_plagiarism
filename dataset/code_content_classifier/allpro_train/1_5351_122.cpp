#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int x[200010]={0},y[200010]={0};
int main(){
	int i,j,k,m,n;
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;i++){	
		int a,b;
		scanf("%d%d",&a,&b);
		if (a==1) x[b]++;
		if (b==m) y[a]++;
	}	
	for (i=1;i<=n;i++)
		if (x[i] && y[i]){
			printf("POSSIBLE\n");
			return 0;
	}	
	printf("IMPOSSIBLE\n");
	return 0;
}