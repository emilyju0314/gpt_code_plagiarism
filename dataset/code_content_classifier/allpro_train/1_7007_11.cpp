#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(long long int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<62;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

void solve(){
    ll x_size,y_size,z_size,a,b,c,n;
    cin >> x_size >> y_size >> z_size >> a >> b >> c >> n;

    vector<ll> cnt1(n);
    rep(i,0,n) cnt1[i]+=(x_size-a)/n;
    rep(x,a+n*((x_size-a)/n),x_size) ++cnt1[(x-a)%n];
    rep(i,0,n) cnt1[i]+=(a+1)/n;
    for(ll x=a-n*((a+1)/n); x>=0; --x) ++cnt1[(a-x)%n];
    --cnt1[0];

    vector<ll> cnt2(n);
    rep(i,0,n) cnt2[i]-=cnt1[i];
    rep(i,0,n) cnt2[i]+=x_size*((y_size-b)/n);
    {
        vector<ll> tmp1(n);
        ll y1=b+n*((y_size-b)/n),z1=c;
        rep(x,0,x_size) ++tmp1[(abs(x-a)+abs(y1-b)+abs(z1-c))%n];
        rep(y,y1,y_size){
            rep(i,0,n) cnt2[i]+=tmp1[i];
            vector<ll> tmp2(n);
            rep(i,0,n) tmp2[i]=tmp1[(i-1+n)%n];
            swap(tmp1,tmp2);
        }
    }
    rep(i,0,n) cnt2[i]+=x_size*((b+1)/n);
    {
        vector<ll> tmp1(n);
        ll y1=b-n*((b+1)/n),z1=c;
        rep(x,0,x_size) ++tmp1[(abs(x-a)+abs(y1-b)+abs(z1-c))%n];
        for(ll y=y1; y>=0; --y){
            rep(i,0,n) cnt2[i]+=tmp1[i];
            vector<ll> tmp2(n);
            rep(i,0,n) tmp2[i]=tmp1[(i-1+n)%n];
            swap(tmp1,tmp2);
        }
    }

    vector<ll> cnt3(n);
    rep(i,0,n) cnt3[i]-=cnt2[i];
    rep(i,0,n) cnt3[i]+=x_size*y_size*((z_size-c)/n);
    {
        vector<ll> tmp1(n),tmp2(n);
        rep(i,0,n) tmp1[i]=cnt2[i];
        rep(z,c+n*((z_size-c)/n),z_size){
            rep(i,0,n) cnt3[i]+=tmp1[i];
            vector<ll> tmp2(n);
            rep(i,0,n) tmp2[i]=tmp1[(i-1+n)%n];
            swap(tmp1,tmp2);
        }
    }
    rep(i,0,n) cnt3[i]+=x_size*y_size*((c+1)/n);
    {
        vector<ll> tmp1(n),tmp2(n);
        rep(i,0,n) tmp1[i]=cnt2[i];
        for(ll z=c-n*((c+1)/n); z>=0; --z){
            rep(i,0,n) cnt3[i]+=tmp1[i];
            vector<ll> tmp2(n);
            rep(i,0,n) tmp2[i]=tmp1[(i-1+n)%n];
            swap(tmp1,tmp2);
        }
    }

    rep(i,0,n) cout << cnt3[i] << (i==n-1?"\n":" ");
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}