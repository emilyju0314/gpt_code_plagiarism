#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contestant {
    int points;
    int effort;
};

bool compareContestant(Contestant c1, Contestant c2) {
    return c1.points > c2.points;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Contestant> contestants(n);
    for(int i = 0; i < n; i++) {
        cin >> contestants[i].points >> contestants[i].effort;
    }

    sort(contestants.begin(), contestants.end(), compareContestant);

    int totalEffort = 0;
    for(int i = 0; i < n; i++) {
        if(contestants[i].points < contestants[k-1].points) {
            break;
        } else {
            totalEffort += contestants[i].effort;
        }
    }

    if(totalEffort == 0) {
        cout << -1 << endl;
    } else {
        cout << totalEffort << endl;
    }

    return 0;
}