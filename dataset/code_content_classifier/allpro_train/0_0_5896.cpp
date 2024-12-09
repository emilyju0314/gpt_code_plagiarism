#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> facts(m), left(m), right(m);
    vector<int> minVal(n + 1, 1), maxVal(n + 1, 1e9);

    for (int i = 0; i < m; i++) {
        cin >> facts[i] >> left[i] >> right[i];
        if (facts[i] == 1) {
            for (int j = left[i]; j < right[i]; j++) {
                minVal[j] = max(minVal[j], minVal[right[i]]);
                maxVal[j] = min(maxVal[j], maxVal[right[i]]);
            }
        }
    }

    bool possible = true;
    for (int i = 0; i < m; i++) {
        if (facts[i] == 0) {
            bool sorted = true;
            for (int j = left[i]; j < right[i] - 1; j++) {
                if (minVal[j] > maxVal[j + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                possible = false;
                break;
            }
        }
    }

    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << minVal[i] << " ";
        }
    }

    return 0;
}