#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    vector<int> dp(100001, 0);
    for (int i = 0; i < n; i++) {
        int currentStrength = strengths[i];
        dp[currentStrength] = 1;
        for(int j = 2 * currentStrength; j <= 100000; j += currentStrength) {
            dp[j] = max(dp[j], dp[currentStrength] + 1);
        }
    }

    int result = 0;
    for (int i = 1; i <= 100000; i++) {
        result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}