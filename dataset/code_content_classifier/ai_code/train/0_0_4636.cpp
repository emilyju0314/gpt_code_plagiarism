#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> pi(n);
    for (int i = 0; i < n; i++) {
        cin >> pi[i];
    }

    vector<double> probabilities(n, 0);
    probabilities[0] = pi[0];

    for (int i = 1; i < n; i++) {
        probabilities[i] = pi[i];
        for (int j = 0; j < i; j++) {
            probabilities[i] += probabilities[j] * pi[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << setprecision(9) << fixed << probabilities[i] << " ";
    }

    return 0;
}