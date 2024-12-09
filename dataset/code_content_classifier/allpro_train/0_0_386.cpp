#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    long long total_sum = 0;
    long long current_sum = 0;
    long long current_min = n;

    for (int i = n - 1; i >= 1; i--) {
        current_min = min(current_min, (long long) a[i]);
        current_sum += current_min - i;
        total_sum += current_sum;
    }

    cout << total_sum << endl;

    return 0;
}