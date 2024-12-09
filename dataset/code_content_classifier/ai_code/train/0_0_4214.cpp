#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> words(n);
    vector<int> max_vals(m, 0);

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        words[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> words[i][j];
            if (words[i][j] > m) {
                words[i][j] -= m;
                max_vals[words[i][j] - 1] = max(max_vals[words[i][j] - 1], l - j);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        bool possible = false;
        for (int j = 0; j < min(words[i - 1].size(), words[i].size()); j++) {
            if (words[i - 1][j] < words[i][j]) {
                possible = true;
                break;
            } else if (words[i - 1][j] > words[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
        if (!possible && words[i - 1].size() > words[i].size()) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << count_if(max_vals.begin(), max_vals.end(), [](int val){ return val > 0; }) << endl;
    for (int i = 0; i < m; i++) {
        if (max_vals[i] > 0) {
            cout << i+1 << " ";
        }
    }
    
    return 0;
}