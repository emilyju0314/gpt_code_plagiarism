#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> depots(n);
        for (int i = 0; i < n; i++) {
            cin >> depots[i];
        }

        sort(depots.begin(), depots.end());

        long long minDistance = 0;
        for (int i = n - 1; i >= 0; i -= k) {
            minDistance += depots[i] - 0;
            if(i - k >= 0) {
                minDistance += depots[i - k] - 0;
            }
        }

        cout << minDistance << endl;
    }

    return 0;
}