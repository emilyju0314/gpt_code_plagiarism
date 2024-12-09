#include <iostream>
#include <vector>

using namespace std;

int queryXOR(vector<int>& indices, int k) {
    cout << "?";
    for (int i = 0; i < k; i++) {
        cout << " " << indices[i] + 1;
    }
    cout << endl;
    cout.flush();

    int result;
    cin >> result;

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        int ans = queryXOR(indices, n);
        cout << "! " << ans << endl;
        return 0;
    }

    if (k == n) {
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        int ans = queryXOR(indices, n);
        cout << "! " << ans << endl;
        return 0;
    }

    if (k == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> indices = {i, j};
                int ans = queryXOR(indices, k);
                if (ans == 0) {
                    vector<int> all_indices(n, 1);
                    for (int l = 0; l < n; l++) {
                        if (l != i && l != j) {
                            all_indices[l] = 0;
                        }
                    }
                    ans = queryXOR(all_indices, n);
                    cout << "! " << ans << endl;
                    return 0;
                }
            }
        }
        cout << -1 << endl;
        return 0;
    }

    // Handling the case for k > 2
    vector<int> xorSums;
    for (int i = 0; i < n; i += k) {
        vector<int> indices;
        for (int j = i; j < min(i + k, n); j++) {
            indices.push_back(j);
        }
        int xorSum = queryXOR(indices, indices.size());
        xorSums.push_back(xorSum);
    }

    int ans = xorSums[0];
    for (int i = 1; i < xorSums.size(); i++) {
        ans ^= xorSums[i];
    }

    cout << "! " << ans << endl;
    return 0;
}