#include<bits/stdc++.h>

using namespace std;
#define MAXN 200020
#define INF 0x3f3f3f3f
#define pb push_back
#define fi first
#define se second
#define All(x) (x).begin(),(x).end()
#define rep(a,b,c) for(ll a=b;a<=c;a++)
#define per(a,b,c) for(ll a=b;a>=c;a--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

namespace fastI {
    #define isDigit(x) (('0'<=(x))&&((x)<='9'))
    #define isBlank(x) (((x)=='\n')||((x)=='\t')||((x)==' ')||((x)==0))
    #define BUF_SIZE 100000
    bool IOerror = 0;
    inline char getc() {
        static char buf[BUF_SIZE];
        static int p = BUF_SIZE, pend = BUF_SIZE;
        if(p == pend) {
            p = 0;
            pend = fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p) {
                IOerror = 1;
                return -1;
            }
        }
        return buf[p++];
    }
    void read(){};
    template<typename T,typename... R>
    void read(T &x,R&... res) {
        x=0;char t=getc();
        while(!IOerror&&!isDigit(t&127))
            t=((t=='-')<<7)|getc();
        while(!IOerror&&isDigit(t&127))
            x=(x<<3)+(x<<1)+(t&127)-'0',
            t=(t&128)|getc();
        if(t&128) x=-x;
        read(res...);
    }
        #undef BUF_SIZE
};
using namespace fastI;

int val[MAXN<<2];

inline int ask(int l,int r){
    cout<<"? "<<l<<' '<<r<<endl;
    int tmp;
    cin>>tmp;
    return (r-l+1)-tmp;
}

#define lson (k<<1)
#define rson (k<<1|1)



inline bool query(int l,int r,int v,int k=1){
    while(l!=r){
        int mid=(l+r)>>1;
        int t=val[lson];
        if(t<0){
            t=ask(l,mid);
            if(t==-1) return false;
            val[lson]=t;
            val[rson]=val[k]-t;
        }
        val[k]--;
        if(t>=v){
            r=mid;
            k=lson;
        }else{
            l=mid+1;
            v-=t;
            k=rson;
        }
    }
    val[k]=0;
    cout<<"! "<<l<<endl;
    return true;
}


int n;
int T;
int k;

int main(){
#ifdef ATOM
freopen("in.txt","r",stdin);
#endif
    cin>>n>>T;
    bool first=true;
    memset(val,-1,sizeof(val));
    while(T--){
        cin>>k;

        if(first){
            val[1]=ask(1,n);
            first=false;
        }
        if(!query(1,n,k)) return 0;
    }

    return 0;
}
