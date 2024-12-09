#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

vector<vector<int>> multisets;

void addInteger(int l, int r, int x) {
    for (int i = l-1; i < r; i++) {
        for (int j = 0; j < multisets[i].size(); j++) {
            if (multisets[i][j] == x) {
                int size = multisets[i].size();
                for (int k = 0; k < size; k++) {
                    multisets[i].push_back(x);
                }
                break;
            }
        }
        multisets[i].push_back(x);
    }
}

int sumOfSizes(int l, int r) {
    int sum = 0;
    for (int i = l-1; i < r; i++) {
        sum = (sum + multisets[i].size()) % MOD;
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;

    multisets.resize(n);

    for (int i = 0; i < q; i++) {
        int t, l, r, x;
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> x;
            addInteger(l, r, x);
        } else {
            cout << sumOfSizes(l, r) << endl;
        }
    }

    return 0;
}