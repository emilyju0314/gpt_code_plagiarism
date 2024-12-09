#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, H;
    cin >> n >> H;

    long long lo = 1, hi = n;
    long long result = 0;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (mid <= H) {
            result = mid;
            lo = mid + 1;
        } else if (mid >= (n + H - 1) / H) {
            result = H;
            break;
        } else {
            long long remainder = n - (mid - 1) * H;
            long long num_full_blocks = (remainder + H - 1) / H;
            if (mid + num_full_blocks > n) {
                hi = mid - 1;
            } else {
                result = mid + num_full_blocks;
                lo = mid + 1;
            }
        }
    }

    cout << result << endl;

    return 0;
}