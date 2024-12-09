#include <iostream>
using namespace std;
int main(void){
    long long mod=1000000007;
    long long H,W,K,i;
    cin >> H >> W >> K;
    if(W==1){
        cout << 1 << endl;
        return 0;
    }
    long long N[W+2],M[W+2],pattern[10];
    for(i=0;i<W+2;i++){
        N[i]=0;
    }
    N[1]=1;
    pattern[0]=1;
    pattern[1]=1;
    for(i=2;i<10;i++){
        pattern[i]=pattern[i-1]+pattern[i-2];
    }
    for(i=0;i<H;i++){
        long long j;
        M[1]=N[1]*pattern[W-1]+N[2]*pattern[W-2];
        for(j=2;j<W;j++){
            M[j]=N[j-1]*pattern[j-2]*pattern[W-j] + N[j]*pattern[j-1]*pattern[W-j] + N[j+1]*pattern[j-1]*pattern[W-j-1];
        }
        M[W]=N[W]*pattern[W-1]+N[W-1]*pattern[W-2];
        for(j=1;j<W+1;j++){
            N[j]=M[j]%mod;
        }
    }
    cout << N[K] << endl;
}