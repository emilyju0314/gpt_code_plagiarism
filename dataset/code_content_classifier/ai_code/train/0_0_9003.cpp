#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> bulbs(N);

    for(int i = 0; i < N; i++) {
        cin >> bulbs[i].first >> bulbs[i].second;
    }

    sort(bulbs.begin(), bulbs.end());

    int numLit = 0;
    int maxLit = 0;
    int currVoltage = 0;

    for(int i = 0; i < N; i++) {
        if(bulbs[i].first > currVoltage) {
            maxLit = max(maxLit, numLit);
            currVoltage = bulbs[i].second;
            numLit = 1;
        } else {
            currVoltage = min(currVoltage, bulbs[i].second);
            numLit++;
        }
    }

    maxLit = max(maxLit, numLit);

    cout << maxLit << endl;

    return 0;
}