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

        long long min_inconvenience = 0;
        for (int i = 0; i < n/2; i++) {
            min_inconvenience += a[n-1-i] - a[i];
        }

        cout << min_inconvenience << endl;
    }

    return 0;
}