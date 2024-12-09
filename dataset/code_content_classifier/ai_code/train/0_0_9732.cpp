#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long inversions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                inversions++;
            }
        }
    }

    long long pairs = 0;
    if (inversions <= k) {
        pairs = (n * (n - 1)) / 2;
    } else {
        // Count pairs with less inversions
        vector<int> prefix_sum(n, 0);
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + a[i-1];
        }
        for (int i = 0; i < n; i++) {
            int l = i, r = n-1;
            for (int j = i; j < n; j++) {
                while (l < j && prefix_sum[j] - prefix_sum[l] + a[l] > k) {
                    l++;
                }
                pairs += l > i ? l - i : 0;
            }
        }
    }

    cout << pairs << endl;

    return 0;
}