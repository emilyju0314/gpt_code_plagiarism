#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> possibleTeams;

    for (long long teams = 1; teams <= n; teams++) {
        long long games = 0;

        long long remainingTeams = teams;
        long long stage1Games = 0;
        long long stage2Games = 0;

        while (remainingTeams % 2 == 0) {
            stage1Games += remainingTeams / 2;
            remainingTeams /= 2;
        }

        if (stage1Games == n) {
            possibleTeams.push_back(teams);
        } else {
            for (long long i = 1; i <= teams; i++) {
                stage2Games += i - 1;
            }

            if (stage1Games + stage2Games == n) {
                possibleTeams.push_back(teams);
            }
        }
    }

    if (possibleTeams.empty()) {
        cout << -1 << endl;
    } else {
        for (long long team : possibleTeams) {
            cout << team << endl;
        }
    }

    return 0;
}