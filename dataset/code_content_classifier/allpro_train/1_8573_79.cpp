#include <bits/stdc++.h>
using namespace std;

#ifdef _MSC_VER
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define fseek_unlocked fseek
#endif

//author : beet_aizu
template <typename T, typename E>
struct SegmentTree
{
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    int n, height;
    F f;
    G g;
    H h;
    T ti;
    E ei;
    vector<T> dat;
    vector<E> laz;
    SegmentTree(F f, G g, H h, T ti, E ei) :
        f(f), g(g), h(h), ti(ti), ei(ei) {}

    void init(int n_) {
        n = 1; height = 0;
        while (n < n_) n <<= 1, height++;
        dat.assign(2 * n, ti);
        laz.assign(2 * n, ei);
    }
    void build(const vector<T>& v) {
        int n_ = v.size();
        init(n_);
        for (int i = 0; i < n_; i++) dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }
    inline T reflect(int k) {
        return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);
    }
    inline void eval(int k) {
        if (laz[k] == ei) return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = ei;
    }
    inline void thrust(int k) {
        for (int i = height; i; i--) eval(k >> i);
    }
    inline void recalc(int k) {
        while (k >>= 1)
            dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }
    inline void recalc(int l, int r) {
        int Xor = l ^ r;
        while (Xor > 1) { 
            Xor >>= 1; l >>= 1; r >>= 1; 
            dat[l] = f(reflect((l << 1) | 0), reflect((l << 1) | 1));
            dat[r] = f(reflect((r << 1) | 0), reflect((r << 1) | 1));
        }
        while (l > 1) {
            l >>= 1;
            dat[l] = f(reflect((l << 1) | 0), reflect((l << 1) | 1));
        }
    }
    void update(int a, int b, E x) {
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) laz[l] = h(laz[l], x), l++;
            if (r & 1) --r, laz[r] = h(laz[r], x);
        }
        recalc(a, b);
    }
    void set_val(int a, T x) {
        thrust(a += n);
        dat[a] = x; laz[a] = ei;
        recalc(a);
    }
    T query(int a, int b) {
        thrust(a += n);
        thrust(b += n - 1);
        T vl = ti, vr = ti;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template<typename C>
    int find(int st, C& check, T& acc, int k, int l, int r) {
        if (l + 1 == r)
        {
            acc = f(acc, reflect(k));
            return check(acc) ? k - n : -1;
        }
        eval(k);
        int m = (l + r) >> 1;
        if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k])))
        {
            acc = f(acc, dat[k]);
            return -1;
        }
        int vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl) return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
    }
    template<typename C>
    int find(int st, C& check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    using P = pair<int, int>;
    auto f = [](P a, P b) { return P(a.first + b.first, a.second + b.second); };
    auto g = [](P a, int b) { return P(a.second * b, a.second); };
    auto h = [](int a, int b) { (void)a; return b; };

    SegmentTree<P, int> ch(f, g, h, P(0, 0), -1010);
    ch.build(vector<P>(n, P(0, 1)));
    for (int i = 0; i < q; i++)
    {
        int c, s, t, x;
        scanf("%d", &c);
        if (c)
        {
            scanf("%d %d", &s, &t);
            printf("%d\n", ch.query(s, t + 1).first);
        }
        else
        {
            scanf("%d %d %d", &s, &t, &x);
            ch.update(s, t + 1, x);
        }
    }
    return 0;
}

