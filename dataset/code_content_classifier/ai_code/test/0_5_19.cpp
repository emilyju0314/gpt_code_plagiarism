#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> segments(n);
        for (int i = 0; i < n; i++) {
            cin >> segments[i];
        }

        int sum = segments[0];
        int maxEndPoint = segments[0];
        
        for (int i = 1; i < n; i++) {
            if (segments[i] > 0) {
                sum += segments[i];
            } else {
                sum -= abs(segments[i]);
            }

            maxEndPoint = max(maxEndPoint, sum);
        }

        cout << maxEndPoint << endl;
    }

    return 0;
}