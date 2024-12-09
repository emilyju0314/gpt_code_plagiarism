#include <bits/stdc++.h>
using namespace std;
const int MD=1e9+7;
int quick_pow(int x,int y) {
    int ans=1;
    while(y){
        if(y&1){
        	ans=1LL*ans*x%MD;
		}
        y>>=1;
        x=1LL*x*x%MD;
    }
    return ans;
}
void add(int &x,int y) {
    x+=y;
    if(x>=MD){
    	x-=MD;
	}
    if(x<0){
    	x+=MD;
	}
}
int main() {
    int n,a,b;
    cin>>n>>a>>b;
    int ans=quick_pow(2,n),s=1;
    add(ans,-1);
    for(int i=1;i<=b;i++) {
        s=1LL*s*(n-i+1)%MD;
		s=1LL*s*quick_pow(i,MD-2)%MD;
        if(i==a){
        	add(ans,-s);
		}
        if(i==b){
        	add(ans,-s);
		}
    }
    cout<<ans<<endl;
    return 0;
}