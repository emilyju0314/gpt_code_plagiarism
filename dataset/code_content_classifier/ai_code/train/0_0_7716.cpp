#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

typedef long long ll;

ll calculateSumOfF(std::vector<int>& arr) {
    ll totalSum = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        ll left_contrib = (i + 1) * (n - i);
        ll right_contrib = (i + 1) * (i + 2);

        totalSum += (left_contrib * right_contrib / 2) % MOD;
        totalSum %= MOD;
    }

    return totalSum;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    ll result = calculateSumOfF(arr);
    std::cout << result << std::endl;

    return 0;
}