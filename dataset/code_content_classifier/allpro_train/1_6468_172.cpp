#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int a[N],b[N];
int main()
{
    int n,m,t;cin>>n>>m;t=(m+1)/2;
    for(int i=1;i<=t;++i) a[i]=i,b[i]=t+t+1-i;
    for(int i=t+1;i<=m;++i) a[i]=t+i,b[i]=a[i]+2*(m-i+1);
    for(int i=1;i<=m;++i) printf("%d %d\n",a[i],b[i]);
}
