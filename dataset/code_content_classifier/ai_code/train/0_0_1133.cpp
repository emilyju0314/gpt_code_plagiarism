#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> temperatures(n);
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    double max_avg_temp = 0;
    for (int i = 0; i < n - k + 1; i++) {
        double sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += temperatures[j];
        }
        double avg_temp = sum / k;
        if (avg_temp > max_avg_temp) {
            max_avg_temp = avg_temp;
        }
    }

    cout << fixed;
    cout.precision(9);
    cout << max_avg_temp << endl;

    return 0;
}