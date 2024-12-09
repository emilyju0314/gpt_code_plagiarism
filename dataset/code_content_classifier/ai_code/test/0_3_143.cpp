#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, int> count;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            count[a[i]]++;
        }

        int mex = 0;
        while (count[mex] > 0) {
            mex++;
        }

        vector<int> operations(n + 1, -1);
        int current = 0;
        for (int i = 0; i <= n; i++) {
            if (count[current] > 0) {
                operations[i] = n - count[current];
            } else {
                while (current < n && count[current] == 0) {
                    current++;
                }
                if (current < n) {
                    operations[i] = n - count[current];
                }
            }
            count[a[i]]--;
        }

        for (int i = 0; i <= n; i++) {
            cout << operations[i] << " ";
        }
        cout << endl;
    }

    return 0;
}