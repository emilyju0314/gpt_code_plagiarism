#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> permutation(n);
        for (int i = 0; i < n; i++) {
            cin >> permutation[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (permutation[i] == i + 1) {
                continue;
            }
            int j = i;
            while (j < n && permutation[j] != i + 1) {
                j++;
            }
            sort(permutation.begin() + i, permutation.begin() + j + 1);
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}