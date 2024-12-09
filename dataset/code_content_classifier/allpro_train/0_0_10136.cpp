#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> changes(n, 0);

    for (int i = 0; i < m; i++) {
        int x, d;
        cin >> x >> d;

        for (int j = 0; j < n; j++) {
            changes[j] += x + d * abs(j - (n-1)/2);
        }
    }

    long double max_mean = 0;
    for (int i = 0; i < n; i++) {
        max_mean += changes[i];
    }

    max_mean /= n;

    cout << fixed;
    cout.precision(15);
    cout << max_mean << endl;

    return 0;
}