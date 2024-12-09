#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> craters(n);

    for (int i = 0; i < n; i++) {
        int center, radius;
        cin >> center >> radius;
        craters[i] = make_pair(center, radius);
    }

    int largestSetSize = 0;
    vector<int> largestSetIndices;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if craters i and j are fully enclosed or do not intersect
            // Logic to check if they satisfy Professor Okulov's theory
            // Update largestSetSize and largestSetIndices if condition is met
        }
    }

    cout << largestSetIndices.size() << endl;
    for (int index : largestSetIndices) {
        cout << index + 1 << " ";
    }
    cout << endl;

    return 0;
}