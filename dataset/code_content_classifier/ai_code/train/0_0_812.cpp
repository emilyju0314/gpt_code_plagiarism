#include <iostream>
#include <vector>

using namespace std;

int maximumIndependentSetSize(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    int result = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    int maxSize = maximumIndependentSetSize(permutation);
    cout << maxSize << endl;

    return 0;
}