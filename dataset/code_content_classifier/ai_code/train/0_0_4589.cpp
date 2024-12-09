#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_time = a[0];
    for (int i = 1; i < n; i++) {
        max_time = max(max_time, a[i] - a[i-1]);
    }

    max_time = max(max_time, M - a[n-1]);

    for (int i = 1; i < n; i++) {
        int time_diff = a[i] - a[i-1];
        max_time = max(max_time, (time_diff - 1) / 2);
    }

    cout << max_time << endl;

    return 0;
}