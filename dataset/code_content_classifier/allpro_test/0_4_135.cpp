#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int score = 0;

        for(int i = 0; i < k; i++) {
            score += a[n-i-1];
        }

        for(int i = 2*k; i < n; i++) {
            score += a[i];
        }

        cout << score << endl;
    }

    return 0;
}