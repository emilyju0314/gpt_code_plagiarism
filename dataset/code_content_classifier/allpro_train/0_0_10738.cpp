#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(const vector<int>& weights, int k, int P) {
    int trucks = 1;
    int currentLoad = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (currentLoad + weights[i] > P) {
            trucks++;
            currentLoad = weights[i];
        } else {
            currentLoad += weights[i];
        }
    }

    return trucks <= k;
}

int minimumMaxLoad(const vector<int>& weights, int k) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isValid(weights, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int result = minimumMaxLoad(weights, k);
    cout << result << endl;

    return 0;
}