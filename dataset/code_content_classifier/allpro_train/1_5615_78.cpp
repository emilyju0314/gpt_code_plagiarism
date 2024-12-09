#include<bits/stdc++.h>
using namespace std;
int N,M,a[1005];
int main(){
	scanf("%d%d",&N,&M);
	int cnt=0;
	for(int i=1;i<=M;i++)
		scanf("%d",&a[i]),cnt+=a[i]%2;
	if(M==1) return (a[1]==1? puts("1\n1\n1"):printf("%d\n2\n%d 1",a[1],a[1]-1)),0;
	if(cnt>2) return puts("Impossible"),0;
	int pos=1;
	for(int i=1;i<=M;i++)
		if(a[i]%2) swap(a[i],a[pos]),pos=M;
	
	if(a[M]==1) swap(a[1],a[M]);
	for(int i=1;i<=M;i++) printf("%d ",a[i]);puts("");
	
	a[1]++;a[M]--;
	if(a[M]==0) M--;
	printf("%d\n",M);
	for(int i=1;i<=M;i++) printf("%d ",a[i]);
	return 0;
} 