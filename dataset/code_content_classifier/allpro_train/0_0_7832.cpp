#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<int> flowers(n);
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    int low = 0;
    int high = 1e9;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        vector<long long> prefixSums(n);
        long long waterNeeded = 0;
        long long totalWater = 0;

        for (int i = 0; i < n; i++) {
            if (flowers[i] < mid) {
                waterNeeded += mid - flowers[i];
            } else {
                totalWater += flowers[i] - mid;
            }

            if (i >= w) {
                totalWater -= prefixSums[i - w];
            }

            prefixSums[i] = totalWater;
            if (i >= m - 1 && waterNeeded <= totalWater) {
                high = mid - 1;
                break;
            }
        }

        if (waterNeeded > totalWater) {
            low = mid;
        }
    }

    cout << low << endl;

    return 0;
}