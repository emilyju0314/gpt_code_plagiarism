#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> deliver_times(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a <= b) {
            deliver_times[b-1] = max(deliver_times[b-1], b - a);
        } else {
            deliver_times[b-1] = max(deliver_times[b-1], b + n - a);
        }
    }

    for (int i = 0; i < n; i++) {
        int total_time = 0;
        for (int j = 0; j < n; j++) {
            total_time = max(total_time, min(abs(j - i), n - abs(j - i)) + deliver_times[j]);
        }
        cout << total_time << " ";
    }

    return 0;
}