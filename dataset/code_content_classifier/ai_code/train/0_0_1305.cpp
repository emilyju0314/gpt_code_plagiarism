#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> employees;
    for (int i = 0; i < N; i++) {
        int Fi, ti;
        cin >> Fi >> ti;
        employees.push_back(make_pair(Fi, ti));
    }

    sort(employees.begin(), employees.end());

    int elevatorPos = 1;
    int totalWaitingTime = 0;
    for (int i = 0; i < N; i++) {
        int Fi = employees[i].first;
        int ti = employees[i].second;
        
        if (Fi < elevatorPos) {
            continue; // Employee missed the elevator
        }

        int distanceMoved = max(Fi - elevatorPos, 0);

        if (D == 1 && distanceMoved != 0) {
            cout << -1 << endl;
            return 0;
        }

        totalWaitingTime += distanceMoved + (D - 1) + abs(Fi - 1);

        elevatorPos = Fi;
    }

    cout << totalWaitingTime << endl;

    return 0;
}