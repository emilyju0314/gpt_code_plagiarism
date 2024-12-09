#include <iostream>
#include <vector>

using namespace std;

bool rearrangeTablesAndFormulas(int n, int k, vector<int>& tables, vector<int>& formulas) {
    for (int i = 0; i < n; i++) {
        int t = tables[i];
        int f = formulas[i];

        if (t > k) {
            if (f < k) {
                swap(t, f);
            } else {
                return false;
            }
        }

        if (t + f > 2 * k) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tables(n);
    vector<int> formulas(n);

    for (int i = 0; i < n; i++) {
        cin >> tables[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> formulas[i];
    }

    if (rearrangeTablesAndFormulas(n, k, tables, formulas)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}