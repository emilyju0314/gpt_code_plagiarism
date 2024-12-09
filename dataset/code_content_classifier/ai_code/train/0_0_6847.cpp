#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long max_sum = 0;
    long long current_sum = 0;
    long long max_original_sum = 0;
    long long max_sum_with_multiplier = 0;

    for(int i = 0; i < n; i++) {
        current_sum = max((long long)a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);

        max_original_sum += a[i];
        max_sum_with_multiplier = max(max_sum_with_multiplier, max_current_sum_with_multiplier);
        max_current_sum_with_multiplier = max(max((long long)a[i], max_current_sum_with_multiplier + a[i]), (long long)a[i]);

    }

    if(max_sum < 0) {
        cout << max_sum << endl;
    } else {
        cout << max(max_original_sum, max_original_sum + (x-1) * max_sum_with_multiplier) << endl;
    }

    return 0;
}