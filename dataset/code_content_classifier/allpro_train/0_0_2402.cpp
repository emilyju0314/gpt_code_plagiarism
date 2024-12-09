#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> probabilities(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> probabilities[i];
    }

    double max_avg = 0.0;
    for (int i = 0; i <= n; i++) {
        double avg = 0.0;
        for (int j = 0; j <= n; j++) {
            if (j <= i) {
                avg += probabilities[j];
            } else {
                avg += probabilities[j] * (double)i / (double)j;
            }
        }
        max_avg = max(max_avg, avg);
    }

    cout << fixed;
    cout.precision(10);
    cout << max_avg << endl;

    return 0;
}