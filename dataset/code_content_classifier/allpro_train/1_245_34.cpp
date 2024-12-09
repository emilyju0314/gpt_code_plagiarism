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

void solve(){
    int n;
    cin >> n;
    int64_t h,a,d,s;
    vector<int64_t> hs,as,ds,ss;
    vector<pair<int64_t,int64_t>> ps;
    vector<int> idx;
    cin >> h >> a >> d >> s;
    rep(i,0,n){
        int64_t h_,a_,d_,s_;
        cin >> h_ >> a_ >> d_ >> s_;
        if(a-d_<=0){
            if(a_-d>0){
                cout << -1 << endl;
                return;
            }
            continue;
        }
        idx.push_back(idx.size());
        ps.push_back(make_pair(max(a_-d,int64_t(0)),(h_+a-d_-1)/(a-d_)-(s_<s?1:0)));
        hs.push_back(h_);
        as.push_back(a_);
        ds.push_back(d_);
        ss.push_back(s_);
    }
    sort(idx.begin(),idx.end(),[&](int i,int j){
        if(a-ds[i]<=0) return true;
        if(a-ds[j]<=0) return false;
        return ps[j].first*((hs[i]+a-ds[i]-1)/(a-ds[i]))>
               ps[i].first*((hs[j]+a-ds[j]-1)/(a-ds[j]));
    });
    int64_t ans=0,sum=0;
    for(int i:idx){
        ans+=ps[i].first*ps[i].second+sum*((hs[i]+a-ds[i]-1)/(a-ds[i]));
        sum+=ps[i].first;
        if(ans>=h){
            cout << -1 << endl;
            return;
        }
    }

    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}