#include <iostream>
#include <vector>

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

        int seconds = 0;
        int prev = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < prev) {
                int diff = prev - a[i];
                int exp = 0;
                while ((1 << exp) - 1 < diff) {
                    exp++;
                }
                seconds = max(seconds, exp);
                a[i] += diff;
            }
            prev = a[i];
        }

        cout << seconds << endl;
    }

    return 0;
}