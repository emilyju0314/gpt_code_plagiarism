#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b;
        for (int i = 0; i < n; i++) {
            b.push_back(a[i] / 2);
            b.push_back(a[i] - a[i] / 2);
        }

        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        cout << b.size() << endl;
    }

    return 0;
}