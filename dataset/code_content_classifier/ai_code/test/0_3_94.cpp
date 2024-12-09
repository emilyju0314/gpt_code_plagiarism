#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> denominations(n);
        for (int i = 0; i < n; i++) {
            cin >> denominations[i];
        }

        long long ans = 1;
        for (int i = 1; i < n; i++) {
            ans = ans * 10 + 1;
        }

        long long res = 1;
        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (res % (long long)pow(10, denominations[i]) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                k--;
                if (k == 0) {
                    break;
                }
            }
            res++;
        }

        cout << res << endl;
    }

    return 0;
}