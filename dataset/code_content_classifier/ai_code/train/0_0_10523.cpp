#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> positions(n);

    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    int distance = positions[n/2] - positions[n/2 - 1];

    cout << distance << endl;

    return 0;
}