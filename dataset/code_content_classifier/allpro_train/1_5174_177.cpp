#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	sort(a,a+n);
	sort(b,b+m);
	if(a[n-1]>=b[0]||a[n-1]>=y||b[0]<=x){
		printf("War\n");
	}else{
		printf("No War\n");
	}
}