#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> depots(n);
        for(int i = 0; i < n; i++) {
            cin >> depots[i];
        }

        sort(depots.begin(), depots.end());

        long long minDistance = 0;
        for(int i = n-1; i >= k; i--) {
            minDistance += 2 * depots[i];
        }

        minDistance += depots[k-1] - depots[0];
        
        cout << minDistance << endl;
    }

    return 0;
}