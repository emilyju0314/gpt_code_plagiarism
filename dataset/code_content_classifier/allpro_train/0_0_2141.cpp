#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> count(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i] % m]++;
    }

    int target = n / m;
    long long moves = 0;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (count[j] > target) {
                if (count[a[i] % m] < target) {
                    count[j]--;
                    count[a[i] % m]++;
                    moves += (j <= a[i] % m) ? a[i] % m - j : m + a[i] % m - j;
                    a[i] = a[i] / m * m + j;
                }
            }
        }
        result[i] = a[i];
    }

    cout << moves << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}