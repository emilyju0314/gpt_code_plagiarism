#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> s(m);
    int total_players = 0;

    for (int i = 0; i < m; i++) {
        cin >> s[i];
        total_players += s[i];
    }

    if (total_players < n) {
        cout << -1 << endl;
    } else {
        double result = 1.0;
        double favorable_outcomes = s[h - 1] - 1;
        double possible_outcomes = total_players - 1;

        for (int i = 0; i < n - 1; i++) {
            result *= favorable_outcomes / possible_outcomes;
            favorable_outcomes--;
            possible_outcomes--;
        }

        cout << fixed << setprecision(6) << 1 - result << endl;
    }

    return 0;
}