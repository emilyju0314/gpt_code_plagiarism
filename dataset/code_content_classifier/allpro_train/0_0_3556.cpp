#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    vector<int> e(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }

    long long gcd = a[0];
    for (int i = 1; i < n; i++) {
        gcd = __gcd(gcd, a[i]);
    }

    if (gcd != 1) {
        cout << -1 << endl;
        return 0;
    }

    long long min_time = 0;
    for (int i = 0; i < n; i++) {
        long long div = a[i];
        while (div > 1 && div % k != 0) {
            div--;
        }

        if (div == 1) {
            cout << -1 << endl;
            return 0;
        }

        min_time += div * e[i];
    }

    cout << min_time << endl;

    return 0;
}