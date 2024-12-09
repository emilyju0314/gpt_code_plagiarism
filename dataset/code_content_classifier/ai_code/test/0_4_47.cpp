#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        int min_distance = 0;
        for (int i = 0; i < n; i += k) {
            int center = x[i + (k-1)/2];
            for (int j = i; j < i + k && j < n; j++) {
                min_distance += abs(x[j] - center);
            }
        }

        cout << min_distance << endl;
    }

    return 0;
}