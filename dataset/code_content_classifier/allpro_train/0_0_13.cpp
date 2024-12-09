#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, l, r;
        cin >> n >> l >> r;

        // Calculate the segment based on the lexicographically smallest cycle pattern
        vector<int> segment;
        int pos = 1;
        int count = 0;
        
        while (count < r) {
            int remaining = r - count;
            int reps = min(remaining, n-1);
            for (int i = 0; i < reps; i++) {
                segment.push_back(pos);
                count++;
            }
            pos++;
        }

        // Print the segment
        for (int i = l-1; i < r; i++) {
            cout << segment[i] << " ";
        }
        cout << endl;
    }

    return 0;
}