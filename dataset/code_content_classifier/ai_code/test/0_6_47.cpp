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

        vector<int> positions(n);
        for(int i = 0; i < n; i++) {
            cin >> positions[i];
        }

        sort(positions.begin(), positions.end());

        long long distance = 0;
        for(int i = 0; i < n; i += k) {
            distance += 2 * (positions[i + k - 1] - positions[i]);
        }

        cout << distance << endl;
    }

    return 0;
}