#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b+c<7){
			printf("NO\n");
			continue;
		} 
		
		ll m = min(a,min(b,c));
		ll s = a+b+c; 
		if(s%9==0&&s/9<=m){
			printf("YES\n");
			continue;
		}
		else{
			printf("NO\n");
		} 
	} 
	return 0;
}

