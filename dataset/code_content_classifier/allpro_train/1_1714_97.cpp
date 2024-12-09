#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=2000005;
const int MOD=1000000007;

int x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6,jc[N],ny[N];
struct data{int x,y,c;}a[4],b[4];

int C(int x1,int y1,int x2,int y2)
{
    return (LL)jc[x2-x1+y2-y1]*ny[x2-x1]%MOD*ny[y2-y1]%MOD;
}

int solve(data a,data b)
{
    int x1=a.x,y1=a.y,x2=b.x,y2=b.y,ans=0;
    for (int i=x3;i<=x4;i++) (ans+=(LL)C(x1,y1,i,y3-1)*C(i,y3,x2,y2)%MOD*(-i-y3)%MOD)%=MOD;
    for (int i=y3;i<=y4;i++) (ans+=(LL)C(x1,y1,x3-1,i)*C(x3,i,x2,y2)%MOD*(-i-x3)%MOD)%=MOD;
    for (int i=x3;i<=x4;i++) (ans+=(LL)C(i,y4+1,x2,y2)*C(x1,y1,i,y4)%MOD*(i+y4+1)%MOD)%=MOD;
    for (int i=y3;i<=y4;i++) (ans+=(LL)C(x4+1,i,x2,y2)*C(x1,y1,x4,i)%MOD*(i+x4+1)%MOD)%=MOD;
    return ans;
}

int main()
{
    scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5,&x6);
    scanf("%d%d%d%d%d%d",&y1,&y2,&y3,&y4,&y5,&y6);
    jc[0]=jc[1]=ny[0]=ny[1]=1;
    for (int i=2;i<=x6+y6;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
    for (int i=2;i<=x6+y6;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
    a[0]=(data){x2,y2,1};a[1]=(data){x2,y1-1,-1};a[2]=(data){x1-1,y2,-1};a[3]=(data){x1-1,y1-1,1};
    b[0]=(data){x6+1,y6+1,1};b[1]=(data){x6+1,y5,-1};b[2]=(data){x5,y6+1,-1};b[3]=(data){x5,y5,1};
    int ans=0;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            (ans+=a[i].c*b[j].c*solve(a[i],b[j]))%=MOD;
    printf("%d",(ans+MOD)%MOD);
    return 0;
}