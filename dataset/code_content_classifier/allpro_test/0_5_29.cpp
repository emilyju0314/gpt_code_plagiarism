#include <iostream>
#include <vector>

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x);
        }
        x = (x * x);
        y /= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];
        }

        long long count = power(2, n);

        long long res = 0;
        for (int i = 1; i < count; i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum += arr[j];
                }
            }
            if (sum == s - 1) {
                res++;
            }
        }

        cout << res << endl;
    }

    return 0;
}