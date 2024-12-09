#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005];
int gcd(int a,int b){
	int t;
	while(b){
		t=a;a=b;b=t%b;
	}
	return a;
}
bool calc(){
	int tot=0,one=0,w;ll tota=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) one=1;
		tota+=a[i];
		if(a[i]&1) tot++,w=i;
	}
	if(one) return 0;
	if(tot!=1) return 0;
	int winner=0;
	int G=0;a[w]--;
	for(int i=1;i<=n;i++) G=gcd(G,a[i]);
	for(int i=1;i<=n;i++) a[i]/=G;
	tot=0;
	for(int i=1;i<=n;i++){
		if(!(a[i]&1)) tot^=1;
	}
	if(!tot) return 1; 
	else return 0;
} 
bool pan(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==1) return a[1]!=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!(a[i]&1)) sum^=1;
	}
	if(sum) return 1;
	int winner=0;
	while(calc()){ 
		winner^=1;
	}
	return winner;
}
int main(){
	if(pan()) puts("First");
	else puts("Second");
	return 0;
}