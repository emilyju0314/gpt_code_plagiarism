#include <iostream>
#include <vector>

using namespace std;

bool isCyclicShift(vector<int>& p, vector<int>& a, int l, int r) {
    int n = p.size();
    int m = r - l + 1;
    int p_index = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] == p[p_index]) {
            p_index++;
            if (p_index == n) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    string result = "";
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; // adjust to 0-based indexing
        r--;
        
        if (isCyclicShift(p, a, l, r)) {
            result += "1";
        } else {
            result += "0";
        }
    }

    cout << result << endl;

    return 0;
}