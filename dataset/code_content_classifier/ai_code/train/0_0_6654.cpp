#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> distances(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> distances[i];
    }

    vector<int> movements(m);
    for (int i = 0; i < m; i++) {
        cin >> movements[i];
    }

    long long totalDistance = 0;
    int currentPosition = 1;
    for (int i = 0; i < m; i++) {
        // Calculate the new position based on the movement
        currentPosition += movements[i];
        // Add the distance travelled on the current day to the total distance
        totalDistance += distances[currentPosition - 2];
    }

    cout << totalDistance % 100000 << endl;

    return 0;
}