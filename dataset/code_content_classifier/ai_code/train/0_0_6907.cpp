#include <iostream>
#include <vector>

using namespace std;

int calculateDepth(int currentContestant, vector<int>& opponents, int currentDepth) {
    if (opponents[currentContestant] == 1) {
        return currentDepth;
    }
    return calculateDepth(opponents[currentContestant], opponents, currentDepth + 1);
}

int main() {
    int N;
    cin >> N;

    vector<int> opponents(N+1);

    for (int i = 2; i <= N; i++) {
        cin >> opponents[i];
    }

    int minDepth = 0;
    for (int i = 2; i <= N; i++) {
        minDepth = max(minDepth, calculateDepth(i, opponents, 1));
    }

    cout << minDepth << endl;

    return 0;
}