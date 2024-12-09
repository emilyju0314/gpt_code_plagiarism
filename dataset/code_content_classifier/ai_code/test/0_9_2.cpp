#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

int countSegments(vector<int>& arr, int n, int m, int k) {
    int totalSegments = 0;
    unordered_map<int, int> sumCount;

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        sum %= k;
        sumCount[sum]++;
    }

    for(auto& it : sumCount) {
        totalSegments += (it.second * (it.second - 1)) / 2;
        totalSegments %= MOD;
    }

    totalSegments = (totalSegments + sumCount[0]) % MOD;

    totalSegments = (totalSegments + 1LL * (m-1) * totalSegments) % MOD;

    return totalSegments;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countSegments(arr, n, m, k);
    cout << result << endl;

    return 0;
}