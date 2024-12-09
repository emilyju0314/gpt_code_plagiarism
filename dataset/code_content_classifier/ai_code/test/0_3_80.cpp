#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1);
    }

    void update(int index, int value) {
        for (; index <= n; index += (index & -index)) {
            tree[index] += value;
        }
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= (index & -index)) {
            sum += tree[index];
        }
        return sum;
    }
};

int countInversions(vector<int>& a, vector<int>& b) {
    int n = a.size();
    sort(a.begin(), a.end());

    FenwickTree ft(n);
    for (int i = 0; i < n; i++) {
        ft.update(i + 1, 1);
    }

    int inversions = 0;
    for (int num : a) {
        inversions += ft.query(upper_bound(a.begin(), a.end(), num) - a.begin());
        ft.update(lower_bound(a.begin(), a.end(), num) - a.begin() + 1, -1);
    }

    for (int num : b) {
        inversions += ft.query(n) - ft.query(upper_bound(a.begin(), a.end(), num) - a.begin());
        ft.update(lower_bound(a.begin(), a.end(), num) - a.begin() + 1, -1);
    }
    
    return inversions;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        int ans = countInversions(a, b);
        cout << ans << endl;
    }

    return 0;
}