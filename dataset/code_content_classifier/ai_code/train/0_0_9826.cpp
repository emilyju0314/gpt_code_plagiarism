#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fighter {
    int points;
    int effort;
};

bool compare(Fighter a, Fighter b) {
    return a.points > b.points;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Fighter> fighters(n);
    for (int i = 0; i < n; i++) {
        int p, e;
        cin >> p >> e;
        fighters[i] = {p, e};
    }

    sort(fighters.begin(), fighters.end(), compare);

    int totalEffort = 0;
    int requiredPoints = fighters[k-1].points;
    for (int i = 0; i < n; i++) {
        if (fighters[i].points < requiredPoints) {
            totalEffort += fighters[i].effort;
        }
    }

    if (fighters[k-1].points < fighters[k].points) {
        cout << totalEffort << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}