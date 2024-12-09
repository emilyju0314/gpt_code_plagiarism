#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prizes(n);
    for (int i = 0; i < n; i++) {
        cin >> prizes[i];
    }

    int totalTime = max(prizes[n-1] - 1, 106 - prizes[0] - 1);
    for (int i = 0; i < n; i++) {
        int timeToReachPrize = min(prizes[i] - 1, 106 - prizes[i] - 1);
        totalTime = max(totalTime, timeToReachPrize);
    }

    cout << totalTime << endl;

    return 0;
}