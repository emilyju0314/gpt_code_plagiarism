#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int calculate_power(int n, int k, int A, int B, vector<int>& avengers, int base_start, int base_end) {
    if (k == 0) {
        return A * (base_end - base_start + 1);
    } else {
        if (base_end == base_start) {
            return B * k * (base_end - base_start + 1);
        } else {
            int base_mid = (base_start + base_end) / 2;
            int left_k = count_if(avengers.begin(), avengers.end(), [=](int pos){ return pos >= base_start && pos <= base_mid; });
            int right_k = k - left_k;
            return min(calculate_power(n-1, left_k, A, B, avengers, base_start, base_mid) + calculate_power(n-1, right_k, A, B, avengers, base_mid+1, base_end),
                       A * (base_end - base_start + 1));
        }
    }
}

int main() {
    int n, k, A, B;
    cin >> n >> k >> A >> B;

    vector<int> avengers(k);
    for (int i = 0; i < k; i++) {
        cin >> avengers[i];
    }

    int ans = calculate_power(n, k, A, B, avengers, 1, pow(2, n));
    
    cout << ans << endl;
    
    return 0;
}