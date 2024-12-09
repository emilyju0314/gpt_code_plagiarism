#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;

int main(void){
    ll N;
    cin>>N;
    rep1(a,3500)rep1(b,a){
        if(4*a*b-N*a-N*b <= 0) continue;
        if((N*a*b)%(4*a*b-N*a-N*b)==0){
            cout<<a<<" "<<b<<" "<<(N*a*b)/(4*a*b-N*a-N*b)<<endl;
            return 0;
        }
    }
}
