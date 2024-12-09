#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double calculateAngle(pair<int, int> p1, pair<int, int> p2) {
    double angle = atan2(p2.second, p2.first) - atan2(p1.second, p1.first);
    angle = fmod(angle + 2*M_PI, 2*M_PI);
    if (angle > M_PI) {
        angle = 2*M_PI - angle;
    }
    return angle * 180 / M_PI;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int,int>> shops(N);
    for (int i = 0; i < N; i++) {
        cin >> shops[i].first >> shops[i].second;
    }

    vector<int> perm(N);
    for (int i = 0; i < N; i++) {
        perm[i] = i;
    }

    double minAngleSum = 1e9;
    do {
        double angleSum = 0;
        pair<int,int> curPos = {0, 0};
        pair<int,int> curDir = {1, 0};
        for (int i = 0; i < N; i++) {
            angleSum += calculateAngle(curDir, {shops[perm[i]].first - curPos.first, shops[perm[i]].second - curPos.second});
            curPos = shops[perm[i]];
            curDir = {shops[perm[i]].first, shops[perm[i]].second};
        }
        angleSum += calculateAngle(curDir, {0 - curPos.first, 0 - curPos.second});
        minAngleSum = min(minAngleSum, angleSum);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << fixed;
    cout.precision(8);
    cout << minAngleSum << endl;

    return 0;
}