#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> servingTimes(n);
    for (int i = 0; i < n; i++) {
        cin >> servingTimes[i];
    }

    sort(servingTimes.begin(), servingTimes.end());

    int notDisappointed = 0;
    int totalWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        if (servingTimes[i] >= totalWaitingTime) {
            notDisappointed++;
        }
        totalWaitingTime += servingTimes[i];
    }

    cout << notDisappointed << endl;

    return 0;
}