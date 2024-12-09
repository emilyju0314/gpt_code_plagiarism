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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int k = 0;
        while (true) {
            int x = a.back();
            vector<int> left, right;
            for (int i = 0; i < n; i++) {
                if (a[i] <= x) {
                    left.push_back(a[i]);
                } else {
                    right.push_back(a[i]);
                }
            }

            if (right.empty()) {
                break;
            }

            a.clear();
            a.insert(a.end(), left.begin(), left.end());
            a.insert(a.end(), right.begin(), right.end());
            k++;
        }

        cout << k << endl;
    }

    return 0;
}