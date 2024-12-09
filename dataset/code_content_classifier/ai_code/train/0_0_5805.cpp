#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> a;

bool compare(vector<int>& row1, vector<int>& row2) {
    int diff_count = 0;
    for (int i = 0; i < m; i++) {
        if (abs(row1[i] - row2[i]) < n) {
            diff_count++;
        }
    }
    return diff_count < m;
}

int main() {
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int max_k = 0;
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }

    do {
        int current_k = 1e9;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                current_k = min(current_k, abs(a[idx[i]][j] - a[idx[i + 1]][j]));
            }
        }
        max_k = max(max_k, current_k);
    } while (next_permutation(idx.begin(), idx.end(), compare));

    cout << max_k << endl;

    return 0;
}