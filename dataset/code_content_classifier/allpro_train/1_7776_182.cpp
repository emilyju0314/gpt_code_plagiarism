#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
int x[maxn],xx[maxn],w[maxn];
int i,j,k,l,r,s,t,n,m;
ll c; 
int main(){
    scanf("%d%d%d",&n,&l,&t);
    fo(i,1,n) scanf("%d%d",&x[i],&w[i]);
    fo(i,1,n){
        if (w[i]==2) w[i]=-1;
        r=x[i]+w[i]*t;
        if (r>0) (c+=r/l)%=n;
        else if (r<0) (c+=(r+1)/l-1)%=n;
        xx[i]=(r%l+l)%l;
    }
    sort(xx+1,xx+n+1);
    c=(c+n)%n;
    fo(i,c+1,n) printf("%d\n",xx[i]);
    fo(i,1,c) printf("%d\n",xx[i]);
}