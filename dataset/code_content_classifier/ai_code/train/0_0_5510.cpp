#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> counts(n, 1);
    int total = n;
    for (int i = 0; i < k; i++) {
        counts[i % n]++;
        if (counts[i % n] > a[i % n]) {
            total--;
        }
        if (total == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (counts[i] <= a[i]) {
            result.push_back(i + 1);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}