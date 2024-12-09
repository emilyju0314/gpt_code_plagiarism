#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Idol {
    int visual;
    int dance;
    int vocal;
};

bool compareIdols(Idol a, Idol b) {
    return a.visual > b.visual;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Idol> idols(n);
    for (int i = 0; i < n; i++) {
        cin >> idols[i].visual >> idols[i].dance >> idols[i].vocal;
    }

    sort(idols.begin(), idols.end(), compareIdols);

    double expected_points = 0;
    for (int i = 1; i <= m; i++) {
        double max_visual = 0, max_dance = 0, max_vocal = 0;
        for (int j = 0; j < n; j++) {
            max_visual = max(max_visual, static_cast<double>(idols[j].visual + i - 1) / i);
            max_dance = max(max_dance, static_cast<double>(idols[j].dance + i - 1) / i);
            max_vocal = max(max_vocal, static_cast<double>(idols[j].vocal + i - 1) / i);
        }

        double curr_expected = max_visual * 5.0 / 9 + max_dance * 3.0 / 9 + max_vocal * 2.0 / 9;
        expected_points = max(expected_points, curr_expected);
    }

    cout << expected_points << endl;

    return 0;
}