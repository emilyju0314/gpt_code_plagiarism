#include<bits/stdc++.h>
using namespace std;
int a[200007];
int main()
{
	int n,m,b;
	scanf("%d",&n);
	m=n-1;
	while(m--){
		scanf("%d",&b);
		a[b]++;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
 } 