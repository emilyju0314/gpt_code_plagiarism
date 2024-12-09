#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n,a[100000];
    long long int ans;
    while(1){
        scanf("%d",&n);
        if(n==0)return 0;
        ans=0;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n-1;i++){
            ans+=a[i]*(n-1-i);
        }
        printf("%lld\n",ans);
    }
}