#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans_x = 0;
    long long min_inversions = 0;

    for(int bit = 30; bit >= 0; bit--) {
        long long set_bits = 0;
        for(int i = 0; i < n; i++) {
            if((a[i] >> bit) & 1) {
                set_bits++;
            }
        }

        long long cur_inversions = (set_bits * (set_bits - 1)) / 2;

        if(cur_inversions < min_inversions) {
            min_inversions = cur_inversions;
            ans_x |= (1 << bit);
        }
    }

    cout << min_inversions << " " << ans_x << endl;

    return 0;
}