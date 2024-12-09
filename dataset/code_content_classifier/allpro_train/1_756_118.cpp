#include<bits/stdc++.h>
using namespace std;

int N,a[101],ans,sum,na[101];

int abs(int v){return v>0?v:-v;}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	for(int i=0;i<N;i++)sum+=a[i],na[i]=N*a[i];
	for(int i=1;i<N;i++)if(abs(na[ans]-sum)>abs(na[i]-sum))ans=i;
	printf("%d\n",ans);
	return 0;
}