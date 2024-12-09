#ifndef __cplusplus
    cat << EOF
#endif
#include <bits/stdc++.h>
using namespace std;

#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define overload_rep(arg0, arg1, arg2, name, ...) name
#define all(box) box.begin(), box.end()

template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if(lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if(lhs > rhs) { lhs = rhs; return 1; } return 0; }

template<class Ab>
struct fenwick_tree {
private:
 
    int size;
    std::vector<Ab> node;
 
public:
 
    fenwick_tree() { }
    fenwick_tree(const int& size_) { init(size_); }
 
    void init(const int& size_) {
        size = size_;
        node.resize(size);
    }
 
    void modify(int idx, const Ab& value) {
        while (idx < size) {
            node[idx] += value;
            idx |= (idx + 1);
        }
    }
 
    Ab get(int idx) const {
        Ab result{};
        while (idx >= 0) {
            result += node[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return result;
    }

};

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A[i] -= K;

    vector<long long> sum(N + 1);
    rep(i, N) {
        sum[i + 1] += A[i];
        sum[i + 1] += sum[i];
    }

    map<long long, int> mp;
    rep(i, N + 1) mp[sum[i]] = 0;

    int cnt = 0;
    for(auto& x : mp) x.second = cnt++;

    fenwick_tree<long long> fen(mp.size());
    long long ans = 0;
    rep(i, N + 1) {
        ans += fen.get(mp[sum[i]]);
        fen.modify(mp[sum[i]], 1);
    }
    cout << ans << '\n';
    return 0;

}


