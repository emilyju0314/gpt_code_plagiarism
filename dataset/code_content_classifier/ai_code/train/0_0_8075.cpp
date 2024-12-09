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

        vector<int> boxes(n);
        long long totalBlocks = 0;
        for (int i = 0; i < n; i++) {
            cin >> boxes[i];
            totalBlocks += boxes[i];
        }

        int maxBlocks = *max_element(boxes.begin(), boxes.end());
        long long extraBlocks = maxBlocks * (n - 1) - totalBlocks;
        cout << extraBlocks << endl;
    }

    return 0;
}