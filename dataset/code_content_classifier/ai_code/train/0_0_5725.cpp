#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<vector<int>> arrays(n, vector<int>());
    vector<int> maxLength(n);

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        maxLength[i] = len;
        arrays[i].resize(len);
        for (int j = 0; j < len; j++) {
            cin >> arrays[i][j];
        }
    }

    vector<long long> columnSums(w, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < maxLength[i]; j++) {
            for (int k = 0; k < w; k++) {
                int start = max(0, k - j);
                int end = min(w - 1, k + maxLength[i] - 1 - j);
                columnSums[k] += *max_element(arrays[i].begin() + max(0, j-k), arrays[i].begin() + min(j + 1, maxLength[i])) 
                                    * (end - start + 1);
            }
        }
    }

    for (int i = 0; i < w; i++) {
        cout << columnSums[i] << " ";
    }

    return 0;
}