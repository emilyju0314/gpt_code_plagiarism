#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<pair<int, int>> passengers; // pair of floor and time of arrival for each passenger

    for (int i = 0; i < n; i++) {
        int fi, ti;
        cin >> fi >> ti;
        passengers.push_back(make_pair(fi, ti));
    }

    sort(passengers.begin(), passengers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // sort passengers based on arrival time in descending order
    });

    int totalTime = 0;
    int currentFloor = s;

    for (int i = 0; i < n; i++) {
        int floor = passengers[i].first;
        int arrivalTime = passengers[i].second;

        totalTime += max(currentFloor - floor, 0) + arrivalTime - max(currentFloor - floor, 0);
        currentFloor = floor;
    }

    totalTime += currentFloor; // add time to reach floor 0 from the last passenger's floor

    cout << totalTime << endl;

    return 0;
}