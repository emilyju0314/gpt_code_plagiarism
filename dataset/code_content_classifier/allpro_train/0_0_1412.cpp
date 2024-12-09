#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;
        vector<long long> a(n);
        long long sum = 0;
        long long minBeauty = 0, maxBeauty = 0;

        for (int j = 0; j < n; j++) {
            cin >> a[j];
            sum += a[j];
            minBeauty += ceil((double)a[j] / x);
        }

        sort(a.begin(), a.end());

        long long curSum = sum;
        for (int j = 0; j < n; j++) {
            if (curSum % x == 0) {
                maxBeauty += curSum / x;
                break;
            } else {
                curSum -= a[j];
                maxBeauty += ceil((double)curSum / x);
            }
        }

        cout << minBeauty << " " << maxBeauty << endl;
    }

    return 0;
}