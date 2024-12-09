#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
using namespace std;
template <class T> void setmax(T & a, T const & b) { if (a < b) a = b; }
int main() {
    // input
    int n; cin >> n;
    vector<vector<int> > g(n);
    repeat (i,n-1) {
        int p, q; cin >> p >> q; -- p; -- q;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    // compute
    int total_leaves = 0;
    repeat (i,n) if (g[i].size() == 1) total_leaves += 1;
    int ans = 0;
    vector<int> middle(n), terminal(n); // dp on tree
    function<void (int, int)> go = [&](int i, int parent) {
        // prepare
        int sum_middle = 0;
        vector<int> terminals;
        vector<int> diff;
        for (int j : g[i]) if (j != parent) {
            go(j, i);
            sum_middle += middle[j];
            terminals.push_back(terminal[j]);
            diff.push_back(terminal[j] - middle[j]);
        }
        diff.push_back(0);
        diff.push_back(0);
        sort(diff.rbegin(), diff.rend());
        terminals.push_back(0);
        terminals.push_back(0);
        sort(terminals.rbegin(), terminals.rend());
        // result
        middle[i] = max(1, sum_middle);
        terminal[i] = max(1 + terminals[0], sum_middle + diff[0]);
        setmax(ans, 1 + terminals[0] + terminals[1]);
        setmax(ans, total_leaves + diff[0] + diff[1]);
    };
    go(0, -1);
    // output
    cout << ans << endl;
    return 0;
}
