#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    double total = 0;
    for (int i = 0; i <= k; i++) {
        double prob = 1.0;
        for (int j = 0; j < n*n - i; j++) {
            prob *= (double)(m - j - k) / (m - j);
        }
        
        double score = pow(2, (n - i) + (n - i));
        total += prob * score;
    }

    if (total > 1e99) {
        cout << fixed << setprecision(10) << "1e99" << endl;
    } else {
        cout << fixed << setprecision(10) << total << endl;
    }

    return 0;
}