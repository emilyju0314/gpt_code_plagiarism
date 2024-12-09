#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int maxTeamSize = 1;
    int currentWeight = weights[0];
    
    for (int i = 1; i < n; i++) {
        if (weights[i] > currentWeight + 1) {
            currentWeight++;
        } else if (weights[i] == currentWeight + 1) {
            currentWeight++;
        }
        maxTeamSize++;
    }

    cout << maxTeamSize << endl;

    return 0;
}