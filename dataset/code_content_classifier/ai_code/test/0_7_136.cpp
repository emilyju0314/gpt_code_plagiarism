#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> b(n);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += b[i];
        }

        bool possible = true;
        for(int i = 0; i < n; i++) {
            if (b[i] > sum) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            long long min_val = *min_element(b.begin(), b.end());
            int idx = find(b.begin(), b.end(), min_val) - b.begin();

            for(int i = 0; i < n; i++) {
                if (i == idx) {
                    cout << min_val << " ";
                } else {
                    cout << (b[i] - min_val + n) % n << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}