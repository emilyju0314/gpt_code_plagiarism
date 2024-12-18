#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-5L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

// geometry library

typedef complex<long double> Point;
typedef pair<complex<long double>, complex<long double>> Line;

typedef struct Circle {
    complex<long double> center;
    long double r;
}Circle;

long double dot(Point a, Point b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}
long double cross(Point a, Point b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

long double Dist_Line_Point(Line a, Point b) {
    if (dot(a.second - a.first, b - a.first) < eps) return abs(b - a.first);
    if (dot(a.first - a.second, b - a.second) < eps) return abs(b - a.second);
    return abs(cross(a.second - a.first, b - a.first)) / abs(a.second - a.first);
}

int is_intersected_ls(Line a, Line b) {
    return (cross(a.second - a.first, b.first - a.first) * cross(a.second - a.first, b.second - a.first) < eps) &&
        (cross(b.second - b.first, a.first - b.first) * cross(b.second - b.first, a.second - b.first) < eps);
}

Point intersection_l(Line a, Line b) {
    Point da = a.second - a.first;
    Point db = b.second - b.first;
    return a.first + da * cross(db, b.first - a.first) / cross(db, da);
}

long double Dist_Line_Line(Line a, Line b) {
    if (is_intersected_ls(a, b) == 1) {
        return 0;
    }
    return min({ Dist_Line_Point(a,b.first), Dist_Line_Point(a,b.second),Dist_Line_Point(b,a.first),Dist_Line_Point(b,a.second) });
}

pair<Point, Point> intersection_Circle_Circle(Circle a, Circle b) {
    long double dist = abs(a.center - b.center);
    assert(dist <= eps + a.r + b.r);
    assert(dist + eps >= abs(a.r - b.r));
    Point target = b.center - a.center;
    long double pointer = target.real() * target.real() + target.imag() * target.imag();
    long double aa = pointer + a.r * a.r - b.r * b.r;
    aa /= 2.0L;
    Point l{ (aa * target.real() + target.imag() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
            (aa * target.imag() - target.real() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer };
    Point r{ (aa * target.real() - target.imag() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
        (aa * target.imag() + target.real() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer };
    r = r + a.center;
    l = l + a.center;
    return mp(l, r);
}

//end of geometry

template<typename A>
A pows(A val, ll b) {
    assert(b >= 1);
    A ans = val;
    b--;
    while (b) {
        if (b % 2) {
            ans *= val;
        }
        val *= val;
        b /= 2LL;
    }
    return ans;
}

template<typename A>
class Compressor {
public:
    bool is_zipped = false;
    map<A, ll> zipper;
    map<ll, A> unzipper;
    queue<A> fetcher;
    Compressor() {
        is_zipped = false;
        zipper.clear();
        unzipper.clear();
    }
    void add(A now) {
        assert(is_zipped == false);
        zipper[now] = 1;
        fetcher.push(now);
    }
    void exec() {
        assert(is_zipped == false);
        int cnt = 0;
        for (auto i = zipper.begin(); i != zipper.end(); ++i) {
            i->second = cnt;
            unzipper[cnt] = i->first;
            cnt++;
        }
        is_zipped = true;
    }
    ll fetch() {
        assert(is_zipped == true);
        A hoge = fetcher.front();
        fetcher.pop();
        return zipper[hoge];
    }
    ll zip(A now) {
        assert(is_zipped == true);
        assert(zipper.find(now) != zipper.end());
        return zipper[now];
    }
    A unzip(ll a) {
        assert(is_zipped == true);
        assert(a < unzipper.size());
        return unzipper[a];
    }
    ll next(A now) {
        auto x = zipper.upper_bound(now);
        if (x == zipper.end()) return zipper.size();
        return (ll)((*x).second);
    }
    ll back(A now) {
        auto x = zipper.lower_bound(now);
        if (x == zipper.begin()) return -1;
        x--;
        return (ll)((*x).second);
    }
};

template<typename A>
class Matrix {
public:
    vector<vector<A>> data;
    Matrix(vector<vector<A>> a) :data(a) {

    }
    Matrix operator + (const Matrix obj) {
        vector<vector<A>> ans;
        assert(obj.data.size() == this->data.size());
        assert(obj.data[0].size() == this->data[0].size());
        REP(i, obj.data.size()) {
            ans.push_back(vector<A>());
            REP(q, obj.data[i].size()) {
                A hoge = obj.data[i][q] + (this->data[i][q]);
                ans.back().push_back(hoge);
            }
        }
        return Matrix(ans);
    }
    Matrix operator - (const Matrix obj) {
        vector<vector<A>> ans;
        assert(obj.data.size() == this->data.size());
        assert(obj.data[0].size() == this->data[0].size());
        REP(i, obj.data.size()) {
            ans.push_back(vector<A>());
            REP(q, obj.data[i].size()) {
                A hoge = this->data[i][q] - obj.data[i][q];
                ans.back().push_back(hoge);
            }
        }
        return Matrix(ans);
    }
    Matrix operator * (const Matrix obj) {
        vector<vector<A>> ans;
        assert(obj.data.size() == this->data[0].size());
        REP(i, this -> data.size()) {
            ans.push_back(vector<A>());
            REP(q, obj.data[0].size()) {
                A hoge = (this->data[i][0]) * (obj.data[0][q]);
                for (int t = 1; t < obj.data[i].size(); ++t) {
                    hoge += this->data[i][t] * obj.data[t][q];
                }
                ans.back().push_back(hoge);
            }
        }
        return Matrix(ans);
    }
    Matrix& operator *= (const Matrix obj) {
        *this = (*this * obj);
        return *this;
    }
    Matrix& operator += (const Matrix obj) {
        *this = (*this + obj);
        return *this;
    }
    Matrix& operator -= (const Matrix obj) {
        *this = (*this - obj);
        return *this;
    }
};

class modint {
public:
    using u64 = std::uint_fast64_t;
    u64 value = 0;
    u64 mod;
    modint(ll a, ll b) : value(((a% b) + 2 * b) % b), mod(b) {

    }
    modint operator+(const modint rhs) const {
        return modint(*this) += rhs;
    }
    modint operator-(const modint rhs) const {
        return modint(*this) -= rhs;
    }
    modint operator*(const modint rhs) const {
        return modint(*this) *= rhs;
    }
    modint operator/(const modint rhs) const {
        return modint(*this) /= rhs;
    }
    modint& operator+=(const modint rhs) {
        assert(rhs.mod == mod);
        value += rhs.value;
        if (value >= mod) {
            value -= mod;
        }
        return *this;
    }
    modint& operator-=(const modint rhs) {
        assert(rhs.mod == mod);
        if (value < rhs.value) {
            value += mod;
        }
        value -= rhs.value;
        return *this;
    }
    modint& operator*=(const modint rhs) {
        assert(rhs.mod == mod);
        value = (value * rhs.value) % mod;
        return *this;
    }
    modint& operator/=(modint rhs) {
        assert(rhs.mod == mod);
        ll rem = mod - 2;
        while (rem) {
            if (rem % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            rem /= 2LL;
        }
        return *this;
    }
    bool operator <(modint rhs) const {
        return value < rhs.value;
    }
    friend ostream& operator<<(ostream& os, modint& p) {
        os << p.value;
        return (os);
    }
};

class Dice {
public:
    vector<ll> vertexs;
    //Up: 0,Left: 1,Center: 2,Right: 3,Adj: 4, Down: 5
    Dice(vector<ll> init) :vertexs(init) {

    }
    //Look from Center
    void RtoL() {
        for (int q = 1; q < 4; ++q) {
            swap(vertexs[q], vertexs[q + 1]);
        }
    }
    void LtoR() {
        for (int q = 3; q >= 1; --q) {
            swap(vertexs[q], vertexs[q + 1]);
        }
    }
    void UtoD() {
        swap(vertexs[5], vertexs[4]);
        swap(vertexs[2], vertexs[5]);
        swap(vertexs[0], vertexs[2]);
    }
    void DtoU() {
        swap(vertexs[0], vertexs[2]);
        swap(vertexs[2], vertexs[5]);
        swap(vertexs[5], vertexs[4]);
    }
    bool ReachAble(Dice now) {
        set<Dice> hoge;
        queue<Dice> next;
        next.push(now);
        hoge.insert(now);
        while (next.empty() == false) {
            Dice seeing = next.front();
            next.pop();
            if (seeing == *this) return true;
            seeing.RtoL();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
            seeing.LtoR();
            seeing.LtoR();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
            seeing.RtoL();
            seeing.UtoD();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
            seeing.DtoU();
            seeing.DtoU();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
        }
        return false;
    }
    bool operator ==(const Dice& a) {
        for (int q = 0; q < 6; ++q) {
            if (a.vertexs[q] != (*this).vertexs[q]) {
                return false;
            }
        }
        return true;
    }
    bool operator <(const Dice& a) const {
        return (*this).vertexs < a.vertexs;
    }
};

pair<Dice, Dice> TwoDimDice(int center, int up) {
    int target = 1;
    while (true) {
        if (center != target && 7 - center != target && up != target && 7 - up != target) {
            break;
        }
        target++;
    }
    return mp(Dice(vector<ll>{up, target, center, 7 - target, 7 - center, 7 - up}), Dice(vector<ll>{up, 7 - target, center, target, 7 - center, 7 - up}));
}

tuple<Dice, Dice, Dice, Dice> OneDimDice(int center) {
    int bo = min(center, 7 - center);
    pair<int, int> goa;
    if (bo == 1) {
        goa = mp(2, 3);
    }
    else if (bo == 2) {
        goa = mp(1, 3);
    }
    else if (bo == 3) {
        goa = mp(1, 2);
    }
    tuple<Dice, Dice, Dice, Dice> now = make_tuple(Dice(vector<ll>{goa.first, goa.second, center, 7 - goa.second, 7 - center, 7 - goa.first}),
        Dice(vector<ll>{goa.first, 7 - goa.second, center, goa.second, 7 - center, 7 - goa.first}),
        Dice(vector<ll>{7 - goa.first, goa.second, center, 7 - goa.second, 7 - center, goa.first}),
        Dice(vector<ll>{7 - goa.first, 7 - goa.second, center, goa.second, 7 - center, goa.first}));
    return now;
}

template<typename A, typename B>
class Dijkstra {
public:
    vector<vector<pair<int, A>>> vertexs;
    B Cost_Function;
    Dijkstra(int n, B cost) : Cost_Function(cost) {
        vertexs = vector<vector<pair<int, A>>>(n, vector<pair<int, A>>{});
    }
    ~Dijkstra() {
        vertexs.clear();
    }
    void add_edge(int a, int b, A c) {
        vertexs[a].push_back(mp(b, c));
    }
    vector<ll> build_result(int StartPoint) {
        vector<ll> dist(vertexs.size(), 2e18);
        dist[StartPoint] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> next;
        next.push(make_pair(0, StartPoint));
        while (next.empty() == false) {
            pair<ll, int> now = next.top();
            next.pop();
            if (dist[now.second] != now.first) continue;
            for (auto x : vertexs[now.second]) {
                ll now_cost = now.first + Cost_Function(x.second);
                if (dist[x.first] > now_cost) {
                    dist[x.first] = now_cost;
                    next.push(mp(now_cost, x.first));
                }
            }
        }
        return dist;
    }
};

class Dinic {
public:
    struct edge {
        int to;
        int cap;
        int rev;
    };
    vector<vector<edge>> Graph;
    vector<int> level;
    vector<int> itr;
    Dinic(int n) {
        Graph = vector<vector<edge>>(n, vector<edge>());
    }
    void add_edge(int a, int b, int cap) {
        Graph[a].push_back(edge{ b, cap ,(int)Graph[b].size() });
        Graph[b].push_back(edge{ a,0,(int)Graph[a].size() - 1 });
    }
    void bfs(int s) {
        level = vector<int>(Graph.size(), -1);
        level[s] = 0;
        queue<int> next;
        next.push(s);
        while (next.empty() == false) {
            int now = next.front();
            next.pop();
            for (auto x : Graph[now]) {
                if (x.cap == 0) continue;
                if (level[x.to] == -1) {
                    level[x.to] = level[now] + 1;
                    next.push(x.to);
                }
            }
        }
    }
    int dfs(int now, int goal, int val) {
        if (goal == now) return val;
        for (int& i = itr[now]; i < (int)Graph[now].size(); ++i) {
            edge& target = Graph[now][i];
            if (target.cap > 0 && level[now] < level[target.to]) {
                int d = dfs(target.to, goal, min(val, target.cap));
                if (d > 0) {
                    target.cap -= d;
                    Graph[target.to][target.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int run(int s, int t) {
        int ans = 0;
        int f = 0;
        while (bfs(s), level[t] >= 0) {
            itr = vector<int>(Graph.size(), 0);
            while ((f = dfs(s, t, 1e9)) > 0) {
                ans += f;
            }
        }
        return ans;
    }
};

//by ei1333
//https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz + 1, M1);
    }

    void set(int k, const Monoid& x) {
        seg[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid& x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int& k) const {
        return seg[k + sz];
    }

    template< typename C >
    int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }


    template< typename C >
    int find_first(int a, const C& check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template< typename C >
    int find_last(int b, const C& check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}
#define int long long
int calc(State &a) {
    int left = 0;
    while(*a == '-') {
        left++;
        a++;
    }
    if (*a == '(') {
        a++;
        left += calc(a);
        a++;
    }
    else {
        left += *a - '0';
        a++;
    }
    left %= 2;
    int trigger = 0;
    if (*a == '*') {
        trigger = 1;
    }
    a++;
    int right = 0;
    while(*a == '-') {
        right++;
        a++;
    }
    if (*a == '(') {
        a++;
        right += calc(a);
        a++;
    }
    else {
        right += *a - '0';
        a++;
    }
    right %= 2;
    if (trigger == 1) {
        return (left & right);
    }
    else {
        return (left ^ right);
    }
}
int check(string s) {
    s = "0^" + s + ")";
    int ans = 0;
    REP(i, 16) {
        int cnt[4] = {};
        REP(q, 4) {
            if ((1 << q) & i) {
                cnt[q] = 1;
            }
        }
        string c;
        REP(q, s.length()) {
            if (s[q] >= 'a' && s[q] <= 'd') {
                c.push_back(cnt[s[q] - 'a'] + '0');
            }
            else {
                c.push_back(s[q]);
            }
        }
        State now = c.begin();
        ans += (1 << i) * (calc(now));
    }
    return ans;
}
map<int, int> gogo;
void solve() {
    vector<string> expr[20];
    expr[1].push_back("1");
    expr[1].push_back("0");
    expr[1].push_back("a");
    expr[1].push_back("b");
    expr[1].push_back("c");
    expr[1].push_back("d");
    set<int> nekos[20];
    for (int q = 2; q <= 16; ++q) {
        for (auto x : expr[q - 1]) {
            if (x[0] == '-') continue;
            expr[q].push_back("-" + x);
        }
        for (int j = 1; j < q - 3; ++j) {
            int right = (q - 3) - j;
            for (auto x : expr[j]) {
                for (auto y : expr[right]) {
                    if (nekos[q].count(check("(" + x + "*" + y + ")")) == 0) {
                        nekos[q].insert(check("(" + x + "*" + y + ")"));
                        expr[q].push_back("(" + x + "*" + y + ")");
                    }
                    if (nekos[q].count(check("(" + x + "^" + y + ")")) == 0) {
                        nekos[q].insert(check("(" + x + "^" + y + ")"));
                        expr[q].push_back("(" + x + "^" + y + ")");
                    }
                }
            }
        }
    }
    for (int q = 1; q <= 16; ++q) {
        for (auto x : expr[q]) {
            int hoge = check(x);
            gogo[hoge] = max(gogo[hoge], 17 - q);
        }
    }
    while (true) {
        string s;
        cin >> s;
        if (s == ".") return;
        int should_be = check(s);
        cout << 17 - gogo[should_be] << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}
