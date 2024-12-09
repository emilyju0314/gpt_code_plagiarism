#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
#define repeat(i,n) repeat_from(i,0,n)
using namespace std;
struct mobile_t {
    int w; // weight
    double l; // left
    double r; // right
};
const double eps = 0.0001;
double evaluate(vector<int> const & p, double r) {
    stack<mobile_t> stk;
    for (int w : p) {
        if (w == 0) {
            if (stk.size() < 2) return -1;
            mobile_t x = stk.top(); stk.pop();
            mobile_t y = stk.top(); stk.pop();
            mobile_t z;
            z.w = x.w + y.w;
            double dx = y.w /(double) (x.w + y.w);
            double dy = x.w /(double) (x.w + y.w);
            z.l = max(x.l + dx, y.l - dy);
            z.r = max(x.r - dx, y.r + dy);
            if (r + eps < z.r + z.l) return -1;
            stk.push(z);
        } else {
            stk.push((mobile_t){ w, 0.0, 0.0 });
        }
    }
    if (stk.size() != 1) return -1;
    return stk.top().l + stk.top().r;
}
int main() {
    int datasets; cin >> datasets;
    repeat (dataset, datasets) {
        double r; cin >> r;
        int s; cin >> s;
        vector<int> w(s); repeat (i,s) cin >> w[i];
        double result = -1;
        vector<int> p;
        repeat (i,s)   p.push_back(w[i]);
        repeat (i,s-1) p.push_back(0);
        sort(p.begin(), p.end());
        do {
            result = max(result, evaluate(p, r));
        } while (next_permutation(p.begin(), p.end()));
        if (result == -1) {
            printf("-1\n");
        } else {
            printf("%.16lf\n", result);
        }
    }
    return 0;
}