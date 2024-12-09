#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MAXN = 55;
const int MAXP = 55;
const int MAXMASK = 1 << 18;

int n, p;
int a[MAXN];
double dp[MAXMASK][MAXP];

double solve(int mask, int sum) {
    if (sum > p) return 0;
    if (mask == (1 << n) - 1) return 1;

    if (dp[mask][sum] >= 0) return dp[mask][sum];

    double ans = 0;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            ans += solve(mask | (1 << i), sum + a[i]);
        }
    }
    return dp[mask][sum] = ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> p;

    for (int i = 0; i < MAXMASK; i++) {
        for (int j = 0; j < MAXP; j++) {
            dp[i][j] = -1;
        }
    }

    double total = solve(0, 0);
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += solve(1 << i, a[i]);
    }

    double average = result / total;
    cout << setprecision(10) << average << endl;

    return 0;
}