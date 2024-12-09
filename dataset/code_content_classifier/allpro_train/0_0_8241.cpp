#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        
        if (sum <= s) {
            cout << "0" << endl;
        } else {
            int max_idx = 0;
            int max_val = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > max_val) {
                    max_idx = i;
                    max_val = a[i];
                }
            }

            long long sum_except_max = sum - a[max_idx];
            if (sum_except_max <= s) {
                cout << max_idx + 1 << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}