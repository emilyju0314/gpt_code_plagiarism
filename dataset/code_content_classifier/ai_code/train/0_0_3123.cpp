#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int max_zeros = 0;

    for(int i = 0; i < n; i++) {
        if (a[i] == 0) {
            max_zeros = max(max_zeros, n - count(b.begin(), b.end(), 0));
        } else {
            long long d = -b[i] / a[i];

            int zeros = 0;
            for(int j = 0; j < n; j++) {
                if (d * a[j] + b[j] == 0) {
                    zeros++;
                }
            }

            max_zeros = max(max_zeros, zeros);
        }
    }

    cout << max_zeros << endl;

    return 0;
}