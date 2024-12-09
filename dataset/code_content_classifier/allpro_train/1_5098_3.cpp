#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

struct BIT{
    int N;
    vector<int> bit;

    void init(int n){
        N = n;
        bit.resize(N+1);
    }
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i&-i;
        }
        return s;
    }
    void add(int i, int x){
        while(i <= N){
            bit[i] += x;
            i += i&-i;
        }
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<P> pos(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[i] = P(a[i],i);
    }
    sort(pos.begin(), pos.end());
    BIT bit;
    bit.init(n);
    for(int i=0;i<n;i++){
        bit.add(i+1,1);
    }
    ll ans = 0, pre = -1;
    for(int i=0;i<n;){
        vector<int> ls;
        pre = pos[i].first;
        while(i<n && pos[i].first == pre){
            int idx = pos[i].second+1;
            ls.push_back(idx);
            bit.add(idx,-1);
            i++;
        }
        for(int idx : ls){
            int lhs, rhs;
            lhs = bit.sum(idx);
            rhs = bit.sum(n)-bit.sum(idx);
            ans += min(lhs,rhs);
        }
    }
    cout << ans << endl;
    return 0;
}

