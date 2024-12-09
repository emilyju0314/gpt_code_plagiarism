#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += a[i];
    }

    if (totalSum % 3 != 0) {
        cout << 0;
        return 0;
    }

    long long prefixSum = 0;
    long long targetSum = totalSum / 3;
    long long count = 0;
    int cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        prefixSum += a[i];
        if (prefixSum == 2 * targetSum) {
            count += cnt;
        }
        if (prefixSum == targetSum) {
            cnt++;
        }
    }

    cout << count;

    return 0;
}