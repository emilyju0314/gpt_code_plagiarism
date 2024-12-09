#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end(), greater<pair<int, int>>());

    long long total_beauty = 0;
    vector<int> partition_points(k - 1);

    for (int i = 0; i < k - 1; i++) {
        partition_points[i] = a[(i + 1) * m - 1].second;
    }

    for (int i = 0; i < n; i++) {
        total_beauty += (i < k * m) ? a[i].first : 0;
    }

    cout << total_beauty << endl;
    for (int p : partition_points) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}