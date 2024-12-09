#include<bits/stdc++.h>
#define cs const
#define pb push_back
using namespace std;
typedef long long ll;
int k, A, B, L, R, T;
bool chk(int p){
	int a = A - p / (k+1) * k - p % (k+1);
	int b = B - p / (k+1); return b <= 1ll * a * k;
}
void Main(){
	scanf("%d%d%d%d",&A,&B,&L,&R);
	k = max((A-1)/(B+1)+1, (B-1)/(A+1)+1);
	int l=0, r=A+B+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid+1; else r=mid;
	} int a = A - l / (k+1) * k - l % (k+1);
	int b = B - l / (k+1);
	r = l + 1 + b - a * k;
	for(int i=L; i<=R; i++){
		if(i<=l){
			if(i % (k+1) == 0) putchar('B');
			else putchar('A');
		}
		else{
			if((i-r) % (k+1)) putchar('B');
			else putchar('A');
		}
	} puts("");
}
int main(){
	#ifdef FSYolanda
	freopen("1.in","r",stdin);
	#endif
	scanf("%d",&T);
	while(T--) Main(); return 0;
}