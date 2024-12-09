#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> gcd_vals(n);
    gcd_vals[0] = arr[0];
    for (int i = 1; i < n; i++) {
        gcd_vals[i] = gcd(gcd_vals[i-1], arr[i]);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int left_gcd = (l == 0) ? 0 : gcd_vals[l-1];
        int subarr_gcd = gcd(gcd_vals[r], left_gcd);

        int count = 0;
        while (l <= r) {
            int subarr_lcm = arr[l];
            int j = l + 1;
            while (j <= r && gcd(arr[j], subarr_lcm) == subarr_lcm) {
                subarr_lcm = (subarr_lcm * arr[j]) / gcd(arr[j], subarr_lcm);
                j++;
            }
            count++;
            l = j;
        }
        cout << count << endl;
    }

    return 0;
}