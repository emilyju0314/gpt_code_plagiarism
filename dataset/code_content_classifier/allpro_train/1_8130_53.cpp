#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

void solve(int n,int s,int w,int q){
    vector<int> a(n);
    {
        int g=s;
        for(int i=0; i<n; i++) {
            a[i]=(g/7)%10;
            if(g%2==0) g=(g/2);
            else g=(g/2)^w;
        }
    }

    if(q==2){
        int ans=0,count=0;
        for(int i=n-1; i>=0; --i){
            if(a[i]%2==0) ++count;
            if(a[i]!=0) ans+=count;
        }
        cout << ans << endl;
        return;
    }
    if(q==5){
        int ans=0,count=0;
        for(int i=n-1; i>=0; --i){
            if(a[i]==0 or a[i]==5) ++count;
            if(a[i]!=0) ans+=count;
        }
        cout << ans << endl;
        return;
    }

    map<int,int> count;
    int64_t k=1,ans=0,x=0;
    ++count[0];
    for(int i=n-1; i>=0; --i){
        x+=a[i]*k;
        x%=q;
        k*=10;
        k%=q;
        if(a[i]!=0) ans+=count[x];
        ++count[x];
    }
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    for(;;){
        int64_t n,s,w,q;
        cin >> n >> s >> w >> q;
        if(n==0 and s==0 and w==0 and q==0) break;
        solve(n,s,w,q);
    }
    return 0;
}