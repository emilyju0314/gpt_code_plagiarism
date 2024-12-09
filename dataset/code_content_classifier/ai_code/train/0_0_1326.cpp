#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long min_cost_to_power_sequence(int n, vector<long long>& arr) {
    sort(arr.begin(), arr.end());
    long long min_cost = 1e18; // Initialize with a large number

    for(int i = 0; i < 100; i++) {
        long long c = pow(arr[n-1], 1.0 / (n - 1));
        long long cost = 0;
        for(int j = 0; j < n; j++) {
            cost += abs(arr[j] - pow(c, j)); // Calculate the cost to transform into power sequence
        }
        min_cost = min(min_cost, cost); // Update minimum cost
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
    }

    return min_cost;
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long ans = min_cost_to_power_sequence(n, arr);
    cout << ans << endl;

    return 0;
}