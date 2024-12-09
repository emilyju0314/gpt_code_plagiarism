#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> probabilities(n);
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }

    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double curr = probabilities[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                curr *= (1 - probabilities[j]);
            }
        }
        result = max(result, curr);
    }

    cout << fixed << setprecision(12) << result << endl;

    return 0;
}