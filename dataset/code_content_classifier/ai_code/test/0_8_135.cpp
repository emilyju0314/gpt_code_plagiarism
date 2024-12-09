#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int score = a.back();
        for (int i = 0; i < k; i++) {
            score += a[n-2*(i+1)];
        }

        cout << score << endl;
    }

    return 0;
}