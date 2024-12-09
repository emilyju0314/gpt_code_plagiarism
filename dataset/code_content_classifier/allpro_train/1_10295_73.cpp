#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
 
#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(__typeof((X).begin()) it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)x.size())
 
using namespace std;
 
struct timer{
    time_t start;
    timer(){start=clock();}
    ~timer(){cerr<<1.*(clock()-start)/CLOCKS_PER_SEC<<" secs"<<endl;}
};
 
typedef istringstream iss;
typedef long long ll;
typedef pair<int,int> pi;
typedef stringstream sst;
typedef vector<int> vi;
 
ll N,H,d[100010],h[100010],sumd[100010];
 
struct segtree{
    ll x;
    int l,r;
    segtree *cl,*cr;
     
    segtree(int l,int r): l(l),r(r){
        if(l+1==r){
            x=h[l];
            return;
        }
        cl=new segtree(l,l+r>>1);
        cr=new segtree(l+r>>1,r);
        x=max(cl->x,cr->x);
    }
     
    void change(int pos,ll v){
        if(pos<l || r<=pos){
            return;
        }
        if(l+1==r){
            x=v;
            return;
        }
        cl->change(pos,v);
        cr->change(pos,v);
        x=max(cl->x,cr->x);
    }
     
    ll query(int L,int R,int& ind){
        if(R<=l || r<=L){
            return -INF*INF;
        }
        if(l+1==r){
            ind=l;
            return x;
        }
        int ind1,ind2;
        ll res1 = cl->query(L,R,ind1);
        ll res2 = cr->query(L,R,ind2);
        if(res1 >= res2){
            ind=ind1;
            return res1;
        }
        ind=ind2;
        return res2;
    }
} *root;
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
     
    cin>>N>>H;
    rep(i,N-1){
        cin>>d[i]>>h[i];
        sumd[i+1]=sumd[i]+d[i];
    }
    root=new segtree(0,N-1);
    ll ans=0,hp=H,from=0;
    rep(i,N-1){
        hp-=d[i];
        //cout<<hp<<" "<<ans<<" "<<from<<endl;
        while(hp<=0){
            ll need=1-hp;
            int ind;
            ll maxi=root->query(from,i+1,ind);
            from=ind;
            ll HPpre=hp+sumd[i+1]-sumd[ind];
            //cout<<hp<<" "<<HPpre<<endl;
            //cout<<from<<" - "<<i<<" : "<<maxi<<"("<<ind<<")"<<endl;
            ll maxtime=(H-HPpre)/maxi;
            ll want=(need+maxi-1)/maxi;
            //cout<<maxtime<<" "<<want<<endl;
            if(want <= maxtime){
                ans+=want;
                hp+=want*maxi;
                break;
            }else{
                ll rest=(H-HPpre)%maxi;
                if(rest==0)from++;
                else root->change(ind,rest);
                ans+=maxtime;
                hp+=maxtime*maxi;
            }
        }
    }
    cout<<ans<<endl;
}