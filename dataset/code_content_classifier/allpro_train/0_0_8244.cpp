#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> heights(n);
        for(int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        int maxPeaks = 0, left = 1;
        int peaks = 0;
        for(int i = 1; i < k - 1; i++) {
            if(heights[i] > heights[i-1] && heights[i] > heights[i+1]) {
                peaks++;
            }
        }
        maxPeaks = peaks;
        int maxStart = 1;

        for(int i = k; i < n; i++) {
            if(heights[i-1] > heights[i-2] && heights[i-1] > heights[i]) {
                peaks--;
            }
            if(heights[i-k+1] > heights[i-k] && heights[i-k+1] > heights[i-k+2]) {
                peaks++;
            }
            if(peaks > maxPeaks) {
                maxPeaks = peaks;
                maxStart = i - k + 2;
            }
        }

        cout << maxPeaks + 1 << " " << maxStart << endl;
    }

    return 0;
}