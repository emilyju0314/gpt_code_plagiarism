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

        sort(a.begin(), a.end());

        vector<int> b;
        bool possible = true;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] > 0) {
                b.push_back(a[0]);
                b.push_back(a[i] - a[0]);
                for (int j = 1; j < i; j++) {
                    b.push_back(a[i] - a[j]);
                }
                for (int j = i + 1; j < n; j++) {
                    b.push_back(a[j] - a[i]);
                }
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
            cout << b.size() << endl;
            for (int num : b) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}