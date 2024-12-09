#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, T, m;
    double c;
    cin >> n >> T >> c;

    vector<int> at(n);
    for(int i = 0; i < n; i++) {
        cin >> at[i];
    }

    cin >> m;
    vector<int> pj(m);
    for(int i = 0; i < m; i++) {
        cin >> pj[i];
    }

    // First algorithm to calculate real values
    vector<double> real_values(m);
    for(int i = 0; i < m; i++) {
        real_values[i] = 0.0;
        for(int j = pj[i] - T; j < pj[i]; j++) {
            real_values[i] += at[j];
        }
        real_values[i] /= T;
    }

    // Second algorithm based on exponential decay
    double mean = 0.0;
    for(int t = 0; t < n; t++) {
        mean = (mean + at[t] / T) / c;

        for(int i = 0; i < m; i++) {
            if (pj[i] == t + 1) {
                double error = abs(real_values[i] - mean) / real_values[i];              
                cout << fixed << setprecision(6) << real_values[i] << " " << mean << " " << error << endl;
            }
        }
    }

    return 0;
}