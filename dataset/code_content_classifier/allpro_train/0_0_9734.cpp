#include <iostream>
#include <iomanip>

using namespace std;

double calculateProbability(int n, int m, int k) {
    double totalWays = 1.0;
    double successfulWays = 1.0;

    for (int i = 1; i <= n + m; i++) {
        totalWays *= i;
        if (i <= m) {
            successfulWays *= (m - i + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        totalWays /= i;
    }

    for (int i = 1; i <= m; i++) {
        successfulWays /= i;
    }

    double probability = successfulWays / totalWays;

    return probability;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    double probability = calculateProbability(n, m, k);
    
    cout << fixed << setprecision(6) << probability << endl;

    return 0;
}