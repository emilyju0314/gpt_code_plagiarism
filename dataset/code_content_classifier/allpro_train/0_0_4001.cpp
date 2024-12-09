#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, x;
        cin >> n >> x;

        vector<int> savings(n);
        for (int i = 0; i < n; i++) {
            cin >> savings[i];
        }

        sort(savings.begin(), savings.end(), greater<int>());

        int max_wealthy = 0;
        long long total_savings = 0;
        for (int i = 0; i < n; i++) {
            total_savings += savings[i];
            if (total_savings >= (long long)(n - i) * x) {
                max_wealthy = n - i;
                break;
            }
        }

        cout << max_wealthy << endl;
    }

    return 0;
}