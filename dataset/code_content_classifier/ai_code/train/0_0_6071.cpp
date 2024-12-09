#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<long long, int> freq;
    long long ans = 0;

    for(int i = 0; i < n; i++) {
        long long num = nums[i];
        long long count = freq[(long long)pow(num, k)];
        ans += count;

        for(int j = 2; j <= 100; j++) {
            long long target = (long long)pow(num, k) / j;
            ans += freq[target];
        }

        freq[num] += 1;
    }

    cout << ans << endl;

    return 0;
}