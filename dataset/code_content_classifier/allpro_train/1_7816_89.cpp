//
//  main.cpp
//  B - Inflation
//
//  Created by 王立盛 on 2021/1/31.
//

#include <iostream>
typedef long long  ll;
ll a[105];
ll b[105];
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,k;
        ll sum=0;
        scanf("%d%d",&n,&k);
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a[i]);
            b[i]=a[i];
            a[i]+=a[i-1];
            
        }
        for (int i=n; i>=2; i--) {
            ll  x=(b[i]*100-1)/k;
            if (x>=a[i-1]) {
                sum+=x+1-a[i-1];
                for (int i2=1; i2<=i-1; i2++) {
                    a[i2]+=x+1-a[i-1];
                }
            }
        }
        printf("%lld\n",sum);
    }
}

   		   	 	 				 		 		  		  		