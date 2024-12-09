#include<stdio.h>

int main(){
    long long t,n,k,lb,rb,ph,rzt;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        
        k--;
        scanf("%lld",&ph);
        lb=ph;
        rb=ph;
        rzt=1;
        for(int l1=1;l1<n;l1++){
            scanf("%lld",&ph);
            lb=lb+k;
            if(ph>lb){
                rzt=0;
            }
            rb-=k;
            if(rb>ph+k){
                rzt=0;
            }
            if(lb>ph+k)lb=ph+k;
            if(rb<ph){
                rb=ph;
            }
        }
        if(rb!=ph){
            rzt=0;
        }
        if(rzt){
            printf("YES\n");
        }else
        {
            printf("NO\n");
        }
        
    }
}