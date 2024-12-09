#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long total_deviation = 0;
    long long current_deviation = 0;
    for (int i = 1; i < n; i++) {
        current_deviation += abs(p[i] - p[i-1]);
    }
    total_deviation = current_deviation;

    for (int i = 1; i < n; i++) {
        current_deviation -= abs(p[i] - p[i-1]);
        current_deviation += abs(p[(i+n-1)%n] - p[(i-1+n-1)%n]);
        if (current_deviation < total_deviation) {
            total_deviation = current_deviation;
        }
    }

    cout << total_deviation << " 0" << endl;

    return 0;
}