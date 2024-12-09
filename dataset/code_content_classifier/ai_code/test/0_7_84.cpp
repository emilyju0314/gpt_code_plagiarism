#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int count_pairs(int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            if (gcd(i, j) >= l) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> x(k+2);
        x[0] = 0;
        x[k+1] = n;

        for (int i = 1; i <= k; i++) {
            cin >> x[i];
        }

        int min_sum = 0;
        for (int i = 1; i <= k+1; i++) {
            min_sum += count_pairs(x[i-1] + 1, x[i]);
        }

        cout << min_sum << endl;
    }

    return 0;
}