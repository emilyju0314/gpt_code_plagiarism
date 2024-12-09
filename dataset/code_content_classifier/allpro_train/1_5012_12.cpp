#line 1 "1549.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1549"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Aug  9 03:20:07 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "/Users/knshnb/competitive_programming/competitive_library/src/DataStructure/WaveletMatrix.hpp"
int popcount(std::uint32_t x) { return __builtin_popcount(x); }
int popcount(std::uint64_t x) { return __builtin_popcountll(x); }

template <class block_type = std::uint64_t> struct BitVector {
    static constexpr int b = sizeof(block_type) * CHAR_BIT;  // blockのサイズ
    int n;
    std::vector<block_type> bit;
    std::vector<int> acc;
    BitVector() {}
    BitVector(int n_) : n(n_), bit(n / b + 1), acc(n / b + 1) {}
    template <bool x = 1> void set(int i) {
        if (x)
            bit[i / b] |= (block_type)1 << (i % b);
        else
            bit[i / b] &= ~((block_type)1 << (i % b));
    }
    void build() {
        for (int i = 0; i < (int)acc.size() - 1; i++) {
            acc[i + 1] = acc[i] + popcount(bit[i]);
        }
    }
    // [0, i)内のxの個数
    template <bool x> int rank(int i) {
        if (x)
            return acc[i / b] + (i % b ? popcount(bit[i / b] << (b - i % b)) : 0);
        else
            return i - rank<true>(i);
    }
    // j番目のxのindex
    template <bool x> int select(int j) {
        int ok = n, ng = -1;
        while (std::abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            (rank<x>(mid + 1, x) > j ? ok : ng) = mid;
        }
        return ok;
    }
};

template <class T, int maxlog = 31, class block_type = std::uint64_t> struct WaveletMatrix {
    using bv_type = BitVector<block_type>;
    std::array<bv_type, maxlog> bvs;      // [maxlog, n]の01行列
    std::array<int, maxlog> offset = {};  // 各列でbitが0になっている要素の数

    WaveletMatrix(const std::vector<T>& a) {
        std::vector<T> cur_data = a;
        for (int k = maxlog - 1; k >= 0; k--) {  // 上位bitから見る
            std::vector<T> zero, one;
            bvs[k] = bv_type(a.size());
            for (int i = 0; i < a.size(); i++) {
                bool bit = cur_data[i] >> k & 1;
                if (bit)
                    one.push_back(cur_data[i]), bvs[k].template set<1>(i);
                else
                    zero.push_back(cur_data[i]);
            }
            offset[k] = zero.size();
            cur_data = std::move(zero);
            cur_data.insert(cur_data.end(), one.begin(), one.end());
            bvs[k].build();
        }
    }
    // [l, r)の{x未満の個数, xの個数, xより大の個数}
    std::array<int, 3> rank_3way(int l, int r, int x) {
        int lt = 0, eq = r - l, gt = 0;
        for (int k = maxlog - 1; k >= 0; k--) {
            int prv_num = r - l;
            if (x >> k & 1) {
                l = offset[k] + bvs[k].template rank<1>(l);
                r = offset[k] + bvs[k].template rank<1>(r);
                lt += prv_num - (r - l);
            } else {
                l = bvs[k].template rank<0>(l);
                r = bvs[k].template rank<0>(r);
                gt += prv_num - (r - l);
            }
            eq -= prv_num - (r - l);
        }
        return {lt, eq, gt};
    }
    // [l, r)内の(小さい方から)j番目(0-index)の数
    int quantile(int l, int r, int j) {
        assert(j < r - l);
        T ret = 0;
        for (int k = maxlog - 1; k >= 0; k--) {
            int zl = bvs[k].template rank<0>(l);
            int zr = bvs[k].template rank<0>(r);
            if (zr - zl > j) {  // kビット目は0
                l = zl;
                r = zr;
            } else {  // kビット目は1
                l = offset[k] + (l - zl);
                r = offset[k] + (r - zr);
                ret |= (T)1 << k;
                j -= zr - zl;
            }
        }
        return ret;
    }
};
#line 1 "/Users/knshnb/competitive_programming/competitive_library/src/Helper/ChminChmax.hpp"
template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }
#line 21 "1549.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n;
    std::cin >> n;
    std::vector<int> a(n);
    REP(i, n) std::cin >> a[i];
    WaveletMatrix<int, 20> wm(a);
    Int Q;
    std::cin >> Q;
    REP(q, Q) {
        Int l, r, d;
        std::cin >> l >> r >> d, r++;
        Int cnt = wm.rank_3way(l, r, d)[0];
        Int ans = 1e9;
        if (cnt > 0) chmin(ans, std::abs(d - wm.quantile(l, r, cnt - 1)));
        if (cnt < r - l) chmin(ans, std::abs(d - wm.quantile(l, r, cnt)));
        std::cout << ans << "\n";
    }
}

