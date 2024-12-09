#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int idx = 0;
        long long sum = 0;

        while (idx < a.size()) {
            if (a[idx] % x == 0) {
                int q = a[idx] / x;
                
                for (int i = 0; i < x; i++) {
                    a.push_back(q);
                }
            } else {
                break;
            }

            idx++;
        }

        for (int i : a) {
            sum += i;
        }

        cout << sum << endl;
    }

    return 0;
}