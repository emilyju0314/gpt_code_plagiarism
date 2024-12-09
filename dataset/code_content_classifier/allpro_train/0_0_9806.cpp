#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    // Minimum occupied houses
    int min_occupied = max(houses[1] - houses[0], houses[n-1] - houses[n-2]) + 1;
    for (int i = 1; i < n-1; i++) {
        min_occupied = max(min_occupied, min(houses[i+1] - houses[i], houses[i] - houses[i-1]) + 1);
    }

    // Maximum occupied houses
    int max_occupied = max(houses[1] - houses[0], houses[n-1] - houses[n-2]) - 1;
    for (int i = 1; i < n-1; i++) {
        max_occupied = max(max_occupied, max(houses[i+1] - houses[i], houses[i] - houses[i-1]) - 1);
    }

    cout << min_occupied << " " << max_occupied << endl;

    return 0;
}