#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=100000;
int cnt=0;
int a[100010];
int prime[100010];
void init();
int main()
{
    ios::sync_with_stdio(false);
    int l,r;
    init();
    scanf("%d %d",&l,&r);
        int ans=0;
        for(int i=l;i<=r;i++)
        {
                int sum=0,n=i;
                for(int j=0;prime[j]*prime[j]<=n;j++)
                {
                    while(!(n%prime[j]))
                    {
                        n/=prime[j];
                        sum++;
                    }
                }
                if(n!=1)
                    sum++;
                if(!a[sum])
                    ans++;
        }
        printf("%d\n",ans);
    return 0;
}
void init()
{
    a[1]=1;
    a[0]=1;

    for(ll i=2; i<=100000; i++)
    {
        if(!a[i])
        {
            prime[cnt++]=i;
            for(ll j=i*i; j<=100000; j+=i)
            {
                a[j]=1;
            }
        }
    }
}


