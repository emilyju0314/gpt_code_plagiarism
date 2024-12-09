#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> positions(k+1, 0); // Initialize positions of items
    for (int i = 1; i <= k; i++) {
        int item;
        cin >> item;
        positions[item] = i; // Store the initial positions
    }

    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        int time = 0;
        for (int j = 0; j < m; j++) {
            int item;
            cin >> item;
            time += positions[item];
            // Update positions after accessing the item
            for (int l = 1; l <= k; l++) {
                if (positions[l] < positions[item]) {
                    positions[l]++;
                }
            }
            positions[item] = 1;
        }
        totalTime += time;
    }

    cout << totalTime << endl;

    return 0;
}