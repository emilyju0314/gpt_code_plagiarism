#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].first >> students[i].second;
    }

    int currentTime = 0;
    int busPosition = 0;
    vector<int> results(n);

    for (int i = 0; i < n; i++) {
        int waitTime = max(students[i].first - currentTime, abs(busPosition - students[i].second));
        currentTime += waitTime;

        if (busPosition != students[i].second) {
            currentTime += 1 + (m / 2);
            busPosition = students[i].second;
        }

        currentTime += busPosition; // drive
        results[i] = currentTime;

        currentTime += 1 + (m / 2); // get off
        busPosition = 0; // bus turns around
    }

    for (int i = 0; i < n; i++) {
        cout << results[i] << " ";
    }

    return 0;
}