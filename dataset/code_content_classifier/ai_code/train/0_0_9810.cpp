#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        long long total_length = abs(r1 - l1) * n;
        long long total_intersection = abs(min(r1, r2) - max(l1, l2)) * n;

        if(total_intersection >= k) {
            cout << "0\n";
        } else {
            long long steps = min(abs(min(r1, r2) - l1), abs(r1 - max(l1, l2))) + min(abs(min(r2, r1) - l2), abs(r2 - max(l2, r1)));
            long long extra_steps = k - total_intersection;

            long long result = steps + 2 * ceil((double)extra_steps / n);
            cout << result << "\n";
        }
    }

    return 0;
}