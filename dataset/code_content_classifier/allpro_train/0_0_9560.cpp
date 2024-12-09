#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> measurements(n);
    for (int i = 0; i < n; i++) {
        cin >> measurements[i];
    }

    sort(measurements.begin(), measurements.end());

    int minRemoved = 0;
    int smallest = measurements[0];
    int largest = measurements[n - 1];

    for (int i = 1; i < n - 1; i++) {
        if (2 * smallest < measurements[i] && measurements[i] < largest / 2) {
            minRemoved++;
        }
    }

    cout << minRemoved << endl;

    return 0;
}