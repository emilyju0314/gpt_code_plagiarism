#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int k = 0; k < t; ++k) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> canReach(n + 2, 0);
        vector<int> count(n + 2, 0);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            count[arr[i]]++;
            while (count[mx] > 0) {
                mx++;
            }
            canReach[mx]--;
            canReach[arr[i]]++;
        }

        canReach[mx] = count[mx] > 0 ? 1 : 0;

        for (int i = 0; i <= n; ++i) {
            cout << (canReach[i] > 0 ? 1 : -1) << " ";
        }
        cout << endl;

    }

    return 0;
}