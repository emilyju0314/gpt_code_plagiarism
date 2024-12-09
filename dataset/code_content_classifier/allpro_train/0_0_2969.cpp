#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, g, r;
    cin >> n >> g >> r;

    vector<int> timeToPass(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> timeToPass[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        // Initialize time taken to reach each intersection
        vector<long long> timeAtIntersection(n + 1, -1);
        timeAtIntersection[0] = t;

        // Initialize the answer assuming no waiting time
        long long ans = timeToPass[0];

        // Loop through each intersection
        for (int j = 0; j <= n; j++) {
            if (timeAtIntersection[j] != -1) {
                // Calculate new time to reach next intersection
                long long timeToNextIntersection = ans + timeToPass[j];
                
                // Calculate the time when the light will change back to green
                long long timeToGreen = timeToNextIntersection % (g + r);
                if (timeToGreen <= g) {
                    // If the light is already green, no waiting time
                    ans = timeToNextIntersection;
                } else {
                    // Calculate the time to wait and reach the next intersection
                    long long waitTime = g + r - timeToGreen;
                    ans = timeToNextIntersection + waitTime;
                }

                // Update the time taken to reach next intersection
                if (j < n) {
                    timeAtIntersection[j + 1] = ans;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}