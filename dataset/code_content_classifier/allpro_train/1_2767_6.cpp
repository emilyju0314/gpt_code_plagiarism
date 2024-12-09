#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;


struct INIT{INIT(){ios::sync_with_stdio(false);cin.tie(0);}}init;
vector<int> f(int N){
    vector<int> res;res.reserve(N);
    int i;
    for(i = 1; i*i < N; i++){
        if(N%i==0){
            res.push_back(i);
            res.push_back(N/i);
        }
    }
    if(i*i==N)res.push_back(i);
    sort(res.begin(),res.end());
    return res;
}

int main(){
    int N; cin >> N;
    vector<int> S(N);
    for(auto& it : S)cin>>it;
    auto y=f(N);
    int res=1;
    for(auto& it : y){
        int T=N/it;
        bool check=[&](){
            for(int m = 0; m < T; m++){
                int p=S[m];
                for(int i = T+m; i < N; i+=T)
                    if(S[i]!=p)return false;
            }
            return true;
        }();
        if(check)res=max(res,it);
    }
    cout<<res<<endl;

    return 0;
}