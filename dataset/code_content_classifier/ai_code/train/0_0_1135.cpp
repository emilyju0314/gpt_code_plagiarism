#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> currentPoints(N);
    vector<int> racePoints(N);

    for (int i = 0; i < N; i++) {
        cin >> currentPoints[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> racePoints[i];
    }

    int targetPoints = currentPoints[D - 1] + racePoints[D - 1];
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (currentPoints[i] > targetPoints) {
            count++;
        }
    }

    cout << count + 1 << endl;

    return 0;
}