#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

#define LL long long

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

template< typename T > inline void read(T &x) {
    bool f; char ch; f=0; x=0; ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 4e3+20;
const int maxm=(int) 1e5+20;
const int maxk=(int) 5e2+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;
bitset<maxn> tar,a[10];
int len[10],lt;

string str;

const int mod=998244353;

void work()
{
    read(n);
    cin >> str ;
    lt = str.size() ; tar = bitset<maxn> (str) ;

    while( lt && !tar[lt-1] ) lt--;

    for(int i=0;i<n;i++)
    {
        cin >> str ;
        len[i] = str.size() ; a[i] = bitset<maxn> (str) ;

        while( len[i] && !a[i][len[i]-1] ) len[i]--;
    }

    int tmp;
    while(1)
    {
        tmp=-1;
        for(int i=0;i<n;i++)
        {
            if(len[i] && (tmp==-1 || len[i]<len[tmp])) tmp=i;
        }

        int flag=1;

        for(int i=0;i<n;i++)
        {
            if(i==tmp || len[i]==0) continue;

            a[i] = a[i] ^ ( a[tmp] << ( len[i] - len[tmp] ) ) ;

//            cout <<" i : " <<i <<endl;
//            for(int j=0;j<len[i];j++) cout <<a[i][j]; cout <<endl;

            while( len[i] && !a[i][len[i]-1] ) len[i]--, flag=0;
        }

//        cout <<"t : " <<endl;
//        for(int k=0;k<n;k++)
//        {
//            for(int i=len[k]-1;~i;i--) cout <<a[k][i]; cout <<endl;
//        }
//        cout <<endl;

        if(flag) break;
    }

//    for(int i=len[tmp]-1;~i;i--) cout <<a[tmp][i]; cout <<endl;
//    cout <<len[tmp] <<endl;

    if(len[tmp]>lt)
    {
        puts("0");
    }
    else
    {
        int ans=0, po=1;
        bitset<maxn> acc, pp=a[tmp];
        for(int i=len[tmp];i<=lt;i++)
        {
            if(tar[i-1])
            {
                ans+=po; if(ans>=mod) ans-=mod;
                acc=acc^pp;
            }
            po<<=1; if(po>=mod) po-=mod;
            pp=pp<<1; if(pp[len[tmp]-1]) pp=pp^a[tmp];
        }

        bool flag=1;
        for(int i=lt-1;~i;i--)
        {
            if(tar[i]>acc[i]) break;
            if(tar[i]<acc[i])
            {
                flag=0;
                break;
            }
        }

//        for(int i=lt-1;~i;i--) cout <<tar[i]; cout <<endl;
//        for(int i=lt-1;~i;i--) cout <<acc[i]; cout <<endl;

//        cout <<flag <<endl;

        ans+=flag;
        if(ans>=mod) ans-=mod;

        printf("%d\n",ans);
    }
}

//--------------end--------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}
