#include <iostream>
#include <vector>

using namespace std;

double calculateCost(int n, int X, vector<int>& p) {
    double c = (double)X / 1000000.0;
    vector<double> dp(n+1, 0.0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 0; j--) {
            dp[j] = max(dp[j], max(0.0, dp[j-1]) + (double)j/p[i] - c);
        }
    }

    double res = 0.0;
    for (int i = 0; i <= n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    int n, X;
    cin >> n >> X;

    vector<int> p(n+1);

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    double optimalProfit = calculateCost(n, X, p);
    cout << fixed;
    cout.precision(10);
    cout << optimalProfit << endl;

    return 0;
}