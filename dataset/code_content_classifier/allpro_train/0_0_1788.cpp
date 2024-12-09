#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;

    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    long long max_time = 0;
    for (int i = 0; i < n; i++) {
        long long time_spent = 0;
        long long arrival_time = c[i];

        long long departure_time = max(t1*(long long)k1, arrival_time) + t1;
        departure_time = max(departure_time, (long long)k1*t1 + t2*(long long)k2);
        departure_time = max(departure_time, (long long)(k1*t1 + k2*t2) + t3*(long long)k3);

        max_time = max(max_time, departure_time);
    }

    cout << max_time << endl;

    return 0;
}