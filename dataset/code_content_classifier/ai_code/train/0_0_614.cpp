#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int max_duration = n * (n + 1) / 2; // Maximum possible duration without reordering
    if (max_duration > k) {
        cout << -1 << endl; // It is impossible to reorder the runners
    } else {
        int remaining_time = k - max_duration;
        vector<int> p(n), q(n);
        
        for (int i = 0; i < n; i++) {
            p[i] = i + 1;
            q[i] = n - i;
        }

        // Reorder the runners to minimize remaining_time
        for (int i = 0; i < n && remaining_time > 0; i++) {
            int diff = min(n - p[i], q[i] - 1);
            p[i] += diff;
            q[i] -= diff;
            remaining_time -= diff;
        }

        cout << k - remaining_time << endl;
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    return 0;
}