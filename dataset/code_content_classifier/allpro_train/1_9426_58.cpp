#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,len,pdA[110000],pdB[110000];
struct atom{
	int w,where;
}A[210000];
int compare(atom k1,atom k2){
	return k1.w<k2.w;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		A[++len]=(atom){k1,i};
	}
	for (int i=1;i<=m;i++){
		int k1; scanf("%d",&k1);
		A[++len]=(atom){k1,-i};
	}
	sort(A+1,A+len+1,compare);
	int num1=m+1,num2=n+1;
	long long ans=0;
	for (int i=1;i<=len;i++)
		if (A[i].where>0){
			num2--; ans+=1ll*A[i].w*num1;
		} else {
			num1--; ans+=1ll*A[i].w*num2;
		}
	cout<<ans<<endl;
}
	