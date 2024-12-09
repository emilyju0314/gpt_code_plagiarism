#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<pair<int, int>> requests; // stores the floor the employee is on and the floor they want to reach
    for (int i = 0; i < n; i++) {
        int start, destination;
        cin >> start >> destination;
        requests.push(make_pair(start, destination));
    }

    int currentFloor = 1;
    int totalTime = 0;
    while (!requests.empty()) {
        int nextFloor = requests.front().first;
        int destination = requests.front().second;
        requests.pop();

        totalTime += abs(nextFloor - currentFloor) + abs(destination - nextFloor) + 3; // moving to next floor, opening door, and closing door
        currentFloor = destination;
    }

    cout << totalTime << endl;

    return 0;
}