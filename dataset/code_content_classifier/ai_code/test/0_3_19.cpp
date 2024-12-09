#include <iostream>
#include <vector>

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

        int coverage = segments[n - 1]; // initialize coverage with the last segment's length

        for (int i = n - 2; i >= 0; i--) {
            coverage = max(coverage - 1, segments[i]); // update coverage range based on the current segment's length
        }

        cout << coverage << endl;
    }

    return 0;
}