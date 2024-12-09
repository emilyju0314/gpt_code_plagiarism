    #include <bits/stdc++.h>
    using namespace std;
    #include <math.h>
    #include <iomanip>
    #include <cstdint>
    #include <string>
    #include <sstream>
    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
    #define rep(i,n) for (int i = 0; i < (n); ++i)
    typedef long long ll;
    using P=pair<ll,ll>;
    const int INF=1001001001;
    const int mod=1e9+7;

    void solve(){
      int n;
      cin>>n;
      int x=(n+1)/2*2+1;
      if(n&1){
        int p=x*x;
        cout<<p-(p+1)/2<<endl;
      }
      else{
        int p=(x+1)/2;
        cout<<p*p<<endl;
      }
    }
    int main(){
      solve();
      return 0;
    }
