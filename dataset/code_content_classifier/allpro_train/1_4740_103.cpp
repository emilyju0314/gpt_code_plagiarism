#include <iostream>
using namespace std;
int main(void){
    long long N,K,k,i;
    cin>>N>>K;
    if(K*2>N+1){
        cout<<-1<<endl;
        return 0;
    }
    long long a[N],b[N],c[N];
    if(N%2==1){
        k=(N+1)/2;
        for(i=0;i<N;i++){
            c[i]=k*5-2+i;
            if(i<k){
                a[i]=k*2-1-i;
            }else{
                a[i]=k*4-2-i;
            }
            b[i]=c[i]-a[i];
        }
        k=k-K;
        for(i=0;i<N;i++){
            a[i]-=k;b[i]-=k;c[i]-=k;
        }
    }else{
        k=N/2;
        for(i=0;i<N;i++){
            c[i]=k*5+i;
            if(i<k){
                a[i]=2*k-1-i;
                b[i]=c[i]-a[i];
            }else{
                a[i]=k*4-1-i;
                b[i]=c[i]-a[i]-1;
            }
        }
        k=k-K;
        for(i=0;i<N;i++){
            a[i]-=k;b[i]-=k;c[i]-=k;
        }
    }
    for(i=0;i<N;i++){
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    }
}
