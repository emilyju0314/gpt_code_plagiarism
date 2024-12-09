#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fighter {
    int points, effort;
};

bool cmp(const Fighter& f1, const Fighter& f2) {
    return f1.points > f2.points;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Fighter> fighters(n);
    for(int i = 0; i < n; i++) {
        cin >> fighters[i].points >> fighters[i].effort;
    }

    sort(fighters.begin(), fighters.end(), cmp);

    int totalEffort = 0;
    int goalPoints = fighters[k-1].points;
    for(int i = 0; i < n; i++) {
        if(fighters[i].points < goalPoints) {
            totalEffort += fighters[i].effort;
        }
    }

    int minEffort = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        if(__builtin_popcount(mask) == n - k + 1) {
            int currPoints = 0, currEffort = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    currPoints += fighters[i].points;
                } else {
                    currEffort += fighters[i].effort;
                }
            }
            if(currPoints >= goalPoints) {
                minEffort = (minEffort == 0) ? currEffort : min(minEffort, currEffort);
            }
        }
    }

    if(minEffort == 0) {
        cout << -1 << endl;
    } else {
        cout << totalEffort + minEffort << endl;
    }

    return 0;
}