#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const int P=1000000007;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int n;
int k,a[maxn],b[maxn];
ll ans,res;
int main(){
    read(n),read(k);
    for (int i=1;i<=n;i++){
        read(a[i]),read(b[i]);
        if ((a[i]&k)==a[i]) ans+=b[i];
    }
    for (int i=0;i<=30;i++){
        int mask=1<<i;
        if (k&mask){
            int tmp=(k^mask)|(mask-1);
            res=0;
            for (int j=1;j<=n;j++){
                if ((a[j]&tmp)==a[j]) res+=b[j];
            }
            ans=max(ans,res);
        }
    }
    cout<<ans<<endl;
    return 0;
}
