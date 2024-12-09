#include<cstdio>
int n,v,cn[2][100001],mx[2][2],num[2][2];
int main(){
	scanf("%d",&n);
	if(n==2) return 0*puts("0");
	for(int i=1;i<=n;i++){
		scanf("%d",&v);
		if(i&1) cn[0][v]++;
		else cn[1][v]++;
	}
	for(int j=0;j<=1;j++)for(int i=1;i<=100000;i++){
		if(cn[j][i]>mx[0][j]) mx[1][j]=mx[0][j],num[1][j]=num[0][j],mx[0][j]=cn[j][i],num[0][j]=i;
		else if(cn[j][i]>mx[1][j]) mx[1][j]=cn[j][i],num[1][j]=i;
	}
	if(num[0][0]!=num[0][1]) printf("%d",n-mx[0][0]-mx[0][1]);
	else{
		int ans=100000;
		for(int i=1;i<=100000;i++){
			if(num[0][1]==i) {if(n-mx[1][1]-cn[0][i]<ans) ans=n-mx[1][1]-cn[0][i];}
			else {if(n-mx[0][1]-cn[0][i]<ans) ans=n-mx[0][1]-cn[0][i];}
		}
		printf("%d",ans);
	}
	return 0;
}