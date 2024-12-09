#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        if(m == 0) {
            cout << 0 << endl;
        } else if(m == 1) {
            cout << n << endl;
        } else {
            int max_pairs = (n-m+1) * (n-m+2) / 2;
            int remaining_zeros = m - 1;

            int min_zeros_in_each = remaining_zeros / (m+1);
            int extra_zeros = remaining_zeros % (m+1);

            int max_pairs_with_extra_zeros = max_pairs - (m+1-extra_zeros) * min_zeros_in_each * (min_zeros_in_each+1) / 2
              - extra_zeros * (min_zeros_in_each + 1) * (min_zeros_in_each + 2) / 2;

            cout << max_pairs_with_extra_zeros << endl;
        }
    }

    return 0;
}