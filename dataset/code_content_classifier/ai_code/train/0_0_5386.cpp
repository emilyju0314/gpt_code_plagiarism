#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

int n;
vector<int> P(MAXN);
vector<int> W(MAXN);
vector<int> bit(MAXN);
vector<int> idx(MAXN);

void update(int i, int val) {
    while (i <= n) {
        bit[i] += val;
        i += i & (-i);
    }
}

int query(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & (-i);
    }
    return res;
}

int main() {
    cin >> n;
  
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        idx[P[i]] = i;
    }

    for (int i = 1; i < n; i++) {
        cin >> W[i];
    }

    for (int i = 1; i <= n; i++) {
        update(i, 1);
    }
  
    long long inversions = 0;
    for (int i = 1; i < n; i++) {
        inversions += query(idx[i]) - 1;
        update(idx[i], -1);
    }

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;

        inversions -= query(idx[P[x]] - 1) - 1 + query(idx[P[y]] - 1) - 1;
        if (idx[P[x]] < idx[P[y]]) inversions += query(idx[P[y]] - 1) - 1;
        if (idx[P[x]] > idx[P[y]]) inversions += query(idx[P[x]] - 1) - 1;

        swap(P[x], P[y]);
        idx[P[x]] = x;
        idx[P[y]] = y;

        cout << inversions << endl;
    }

    return 0;
}