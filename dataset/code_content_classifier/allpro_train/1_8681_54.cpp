#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<stack>
#include<cmath>

 
using namespace std;

#ifndef POJ
    #define Cpp11
#endif
 
#ifdef Cpp11
    #define _for(i,a,b) for(auto i = (a);i<(b);++i)
    #define _rep(i,a,b) for(auto i = (a);i<=(b);++i)
    #define _dep(i,a,b) for(auto i = (a);i>=(b);--i)
    #define mt(a,b,c) make_tuple(a,b,c) 
    #include<ctime>
    #include<random>
    #include<chrono>
    #include<limits>
    #include<complex>
    #include<unordered_set>
    #include<unordered_map>
    #include<cassert>
    #include<functional>
    #include<bitset>
    #define IO ios::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
#endif
 
#ifndef Cpp11
    #define _for(i,a,b) for(int i = (a);i<(b);++i)
    #define _rep(i,a,b) for(int i = (a);i<=(b);++i)
    #define _dep(i,a,b) for(int i = (a);i>=(b);--i)
    #define IO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#endif
 
 
using namespace std;


 
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define sci(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define debugline fprintf(stderr,"-----------------------\n");
#define szint(x) ((int)(x).size())


 
#ifdef I128IO
typedef __int128 SPLL;
char buff[200];
template<typename T>
void read(T& o)
{
    o = 0;
    scanf("%s",buff);
    //printf("%s\n",buff);
    T f = 1;
    int i = 0;
 
    if(buff[0]=='-')i++,f = -1;
    for(;buff[i];++i)
    {
        o*=10,o+=buff[i]-'0';
    }
    o*=f;
}
 
template<typename T>
void write(T o)
{
    int len = 0;
    buff[0] = '0';
    if(o==0)
    {
        putchar('0');
        return;
    }
    int f = 1;
    if(o<0) f = -1;
    o*=f;
    for(;o;o/=10) buff[len++] = o%10+'0';
    if(f==-1) buff[len++] = '-';
    reverse(buff,buff+len);
    buff[len++] ='\0';
    printf("%s",buff);
}
#endif
 
#ifdef FIO
char buff[100];
template<typename T>
void read(T& o)
{
    o = 0;
    scanf("%s",buff);
    //printf("%s\n",buff);
    T f = 1;
    int i = 0;
    if(buff[0]=='-')i++,f = -1;
    for(;buff[i];++i)
    {
        o*=10,o+=buff[i]-'0';
    }
    o*=f;
}
template<typename T>
void write(T o)
{
    int len = 0;
    buff[0] = '0';
    if(o==0)
    {
        putchar('0');
        return;
    }
    int f = 1;
    if(o<0) f = -1;
    o*=f;
    for(;o;o/=10) buff[len++] = o%10+'0';
    if(f==-1) buff[len++] = '-';
    reverse(buff,buff+len);
    buff[len++] ='\0';
    printf("%s",buff);
}
#endif

#define OIreader


#ifdef OIreader
inline int read(){
    char ch; bool sign=0; int res=0;
    while(!isdigit(ch=getchar()))if(ch=='-')sign=1;
    while(isdigit(ch))res=res*10+(ch^48),ch=getchar();
    if(sign)return -res; else return res;
}
#endif

#define _Random_

#ifdef _Random_
    mt19937 __MT(chrono::system_clock::now().time_since_epoch().count());
#endif
 
#ifndef BigNumber
    typedef unsigned long long uLL;
    typedef long long LL;
    typedef long long ll;
    typedef pair<LL,LL> pLL;
    typedef vector<LL> vL;
    typedef vector<vL> vLL;
#endif

typedef vector<int> vi;
typedef vector<vi > vii;
typedef pair<int,int> pii;


const int maxn = 200000+5;
const int maxm = 60;
const int apsz = 26;
const int mod = 998244353;
const LL inf = 1e18;


map<int,int> seg[2];
int a[maxn],b[maxn],n;

inline LL solve()
{
    LL ans = 0;
    _rep(i,1,n)
    {
        if(a[i]<=b[i])
        {
            if(!seg[0].count(a[i]))seg[0][a[i]] = 0;
            seg[0][a[i]] = max(seg[0][a[i]],b[i]);
        }
        else
        {
            if(!seg[1].count(b[i]))
            {
                seg[1][b[i]] = 0;
            }
            seg[1][b[i]] = max(seg[1][b[i]],a[i]);
        }
    }
    _for(i,0,2)
    {
        int pre =  -1;
        for(auto it = seg[i].begin();it!=seg[i].end();++it)
        {
            it->sc = max(it->sc,pre);
            pre = it->sc;
        }
    }
    int overlap = 0;
    _rep(i,1,n)
    {
        if(a[i]<=b[i])
        {
            auto it = seg[1].lower_bound(a[i]);
            //cerr<<it->sc<<endl;
            if(it!=seg[1].begin()||it->fr==a[i])
            {
                if(it->fr!=a[i])it--;
                overlap = max(overlap,min(it->sc,b[i])-a[i]);
                //cerr<<
            }
        }
        else
        {
            auto it = seg[0].lower_bound(b[i]);
            if(it!=seg[0].begin()||it->fr==b[i])
            {
                if(it->fr!=b[i])it--;
                overlap = max(overlap,min(it->sc,a[i])-b[i]);
            }
        }
    }
    //cerr<<overlap<<endl;
    _rep(i,1,n) ans+=abs(a[i]-b[i]);
    return ans-2*overlap;
}


int main(void)
{
    sci(n);
    _rep(i,1,n) sci(a[i]);
    _rep(i,1,n) sci(b[i]);
    printf("%lld\n",solve());
    return 0;
}