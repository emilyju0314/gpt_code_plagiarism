#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_permutation(vector<int>& perm) {
    int n = perm.size();
    int k = n - 2;
    while (k >= 0 && perm[k] >= perm[k + 1]) {
        k--;
    }
    if (k == -1) {
        return false;
    }
    int l = n - 1;
    while (perm[k] >= perm[l]) {
        l--;
    }
    swap(perm[k], perm[l]);
    reverse(perm.begin() + k + 1, perm.end());
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> perm(m + 1);
    for (int i = 0; i <= m; i++) {
        cin >> perm[i];
    }

    while (true) {
        bool valid = true;
        for (int i = 0; i < m; i++) {
            int a = perm[i];
            int b = perm[i + 1];

            if (find(perm.begin(), perm.end(), b) - find(perm.begin(), perm.end(), a) != 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int i = 0; i <= m; i++) {
                cout << perm[i] << " ";
            }
            cout << endl;
            return 0;
        }

        if (!next_permutation(perm)) {
            break;
        }
    }

    cout << "No solution" << endl;

    return 0;
}