#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> products(n);
    for(int i = 0; i < n; i++) {
        products[i] = a[i];
    }

    int ops = k / 2;

    while(ops--) {
        vector<long long> prefixProducts(n + 1, 1);
        vector<long long> suffixProducts(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            prefixProducts[i] = prefixProducts[i - 1] * a[i - 1];
        }

        for(int i = n - 1; i >= 0; i--) {
            suffixProducts[i] = suffixProducts[i + 1] * a[i];
        }

        for(int i = 0; i < n; i++) {
            products[i] = max(prefixProducts[i] * power(x, k % 2), suffixProducts[i + 1]);
        }

        for(int i = 0; i < n; i++) {
            a[i] += x;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}