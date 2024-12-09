#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return ((long long)a * b) / gcd(a, b);
}

int beauty(vector<int> &arr) {
    int n = arr.size();
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (lcm(arr[i], arr[j]) % gcd(arr[i], arr[j]) == 0) {
                    cnt++;
                }
            }
        }
        maxD = max(maxD, cnt);
    }
    return maxD;
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

        int q;
        cin >> q;

        while (q--) {
            long long w;
            cin >> w;

            if (w == 0) {
                cout << beauty(arr) << endl;
            } else {
                cout << n << endl;
            }
        }
    }

    return 0;
}