#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        map<int, pair<int, int>> ranges; // Map to store ranges picked by Alice

        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            ranges[r - l + 1] = {l, r};
        }

        int num = 1; // Starting number picked by Bob

        // Iterate through the map in ascending order of range sizes
        for (auto it = ranges.begin(); it != ranges.end(); it++) {
            int l = it->second.first; // start of range
            int r = it->second.second; // end of range
            cout << l << " " << r << " " << num << endl;
            num++;
        }
    }

    return 0;
}