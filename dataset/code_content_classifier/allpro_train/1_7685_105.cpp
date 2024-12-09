#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
const int MD = 998244353;
int n, sz, G, R, B, GR, RB, BG;
ll ans = 1;
char s[300005];
int main(){
	scanf("%d\n%s", &n, s);
	sz = (int)strlen(s);
	rep(i,n) (ans *= (i+1)) %= MD;
	rep(i,sz){
		if(s[i] == 'R'){
			if(BG) ans = ans * BG-- % MD;
			else if(B){
				ans = ans * B-- % MD;
				RB++;
			}else if(G){
				ans = ans * G-- % MD;
				GR++;
			}else R++;
		}else if(s[i] == 'G'){
			if(RB) ans = ans * RB-- % MD;
			else if(R){
				ans = ans * R-- % MD;
				GR++;
			}else if(B){
				ans = ans * B-- % MD;
				BG++;
			}else G++;
		}else{
			if(GR) ans = ans * GR-- % MD;
			else if(G){
				ans = ans * G-- % MD;
				BG++;
			}else  if(R){
				ans = ans * R-- % MD;
				RB++;
			} else B++;
		}
	}
	printf("%lld\n", ans);
}