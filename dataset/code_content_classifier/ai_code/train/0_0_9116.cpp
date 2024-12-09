#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long max_sum = 0;
    long long current_sum = 0;
    long long total_product = 0;
    long long current_product = 0;

    for (int i = 0; i < n; i++) {
        current_sum += a[i] * b[i];
        total_product += a[i] * b[i];
        current_product = max(current_product + a[i] * b[i], (long long)a[i] * b[i]);
        max_sum = max(max_sum, current_product);

        if (current_product < 0) {
            current_product = 0;
        }
    }

    current_sum = 0;
    current_product = 0;

    for (int i = n-1; i >= 0; i--) {
        current_sum += a[i] * b[i];
        current_product = max(current_product + a[i] * b[i], (long long)a[i] * b[i]);
        max_sum = max(max_sum, current_product + total_product - current_sum);

        if (current_product < 0) {
            current_product = 0;
        }
    }

    cout << max_sum << endl;

    return 0;
}