#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, n;
    cin >> T >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_time = 0;
    vector<long long> segments(n, 0);
    for (int i = 0; i < n; i++) {
        segments[i] = ((T - (a[i] % T)) % T) * (n - 1) + i + 1;
        total_time += segments[i];
    }

    for (int i = 0; i < n; i++) {
        cout << (total_time - segments[i]) / T << " ";
    }
    cout << endl;

    return 0;
}