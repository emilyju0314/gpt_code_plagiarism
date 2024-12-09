#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Minion {
    int power;
    int increase;
    int index;
};

bool compareMinions(const Minion &m1, const Minion &m2) {
    return m1.power > m2.power;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        
        vector<Minion> minions(n);
        for (int i = 0; i < n; i++) {
            cin >> minions[i].power >> minions[i].increase;
            minions[i].index = i + 1;
        }

        sort(minions.begin(), minions.end(), compareMinions);

        vector<int> actions;
        int numActions = 0;
        for (int i = 0; i < k; i++) {
            numActions++;
            actions.push_back(minions[i].index);
            for (int j = 0; j < i; j++) {
                minions[j].power += minions[j].increase;
            }
        }

        cout << numActions << endl;
        for (int i = 0; i < numActions; i++) {
            cout << actions[i] << " ";
        }

        cout << endl;
    }

    return 0;
}