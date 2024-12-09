#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, pair<int, int>>> redBalls;
    vector<pair<int, pair<int, int>>> blueBalls;

    for (int i = 0; i < N; i++) {
        int RX, RY, RC;
        cin >> RX >> RY >> RC;
        redBalls.push_back({RC, {RX, RY}});
    }

    for (int i = 0; i < N; i++) {
        int BX, BY, BC;
        cin >> BX >> BY >> BC;
        blueBalls.push_back({BC, {BX, BY}});
    }

    sort(redBalls.rbegin(), redBalls.rend());
    sort(blueBalls.rbegin(), blueBalls.rend());

    long long totalScore = 0;

    for (int i = 0; i < N; i++) {
        int rx = redBalls[i].second.first;
        int ry = redBalls[i].second.second;
        int bx = blueBalls[i].second.first;
        int by = blueBalls[i].second.second;

        totalScore += abs(rx - bx) + abs(ry - by);
    }

    cout << totalScore << endl;

    return 0;
}