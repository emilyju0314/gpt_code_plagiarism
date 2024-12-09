#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int l,r;
	bool operator < (const Node &b)const{return l<b.l;}
}a[N];
int main(){
	int n,x,l,ans=0,now=-1e9;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&x,&l),a[i].l=x-l,a[i].r=x+l;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i].l>=now)ans++,now=a[i].r;
		else if(a[i].r<now)now=a[i].r;
	}
	printf("%d",ans);
	return 0;
}