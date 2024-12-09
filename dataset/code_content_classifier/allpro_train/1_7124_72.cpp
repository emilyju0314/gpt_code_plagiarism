#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<cstdlib>
#include<utility>
#include<bitset>
using namespace std;
bitset<200000+5>f[100+5];
int a[100+5];
int gcd(int a,int b)
{
    if (!b)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int n,V=0,i,id=0,G=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]),V+=a[i],G=gcd(G,a[i]);
    V/=G;
    for (i=1;i<=n;i++)
        a[i]/=G;
    if (V&1)
    {
        printf("0\n");
        return 0;
    }
    f[0][0]=1;
    for (i=1;i<=n;i++)
    {
        f[i].reset();
        f[i]=f[i-1];
        f[i]|=f[i-1]<<a[i];
    }
    if (!f[n][V/2])
    {
        printf("0\n");
        return 0;
    }
    for (i=1;i<=n;i++)
        if (a[i]&1)
            id=i;
    printf("1\n%d\n",id);
}
