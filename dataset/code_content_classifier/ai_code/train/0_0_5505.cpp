#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, n1, n2;
    cin >> n >> n1 >> n2;

    vector<int> wealth(n);
    for (int i = 0; i < n; i++) {
        cin >> wealth[i];
    }

    sort(wealth.begin(), wealth.end(), greater<int>());

    double max_arithmetic_mean = 0.0;
    for (int i = 0; i <= min(n1, n); i++) {
        int j = n1 + n2 - i;
        if (j > n || j < 0) {
            continue;
        }

        double sum = 0.0;
        for (int k = 0; k < i; k++) {
            sum += wealth[k];
        }
        for (int k = n - 1; k >= j; k--) {
            sum += wealth[k];
        }
        
        double arithmetic_mean = sum / (double)(n1 + n2);
        max_arithmetic_mean = max(max_arithmetic_mean, arithmetic_mean);
    }

    cout << fixed;
    cout.precision(8);
    cout << max_arithmetic_mean << endl;

    return 0;
}