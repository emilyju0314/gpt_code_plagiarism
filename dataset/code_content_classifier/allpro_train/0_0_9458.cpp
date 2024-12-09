#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (4 * n * m - 2 * n - 2 * m < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        vector<pair<int, string>> steps;
        int moves = 0;
        while (k > 0) {
            int f = min(3000, k);
            string s;
            if (moves <= m - 1) {
                s = "R";
                moves++;
            } else if (moves <= (m - 1) + (n - 1)) {
                s = "D";
                moves++;
            } else if (moves <= 2 * (m - 1) + (n - 1)) {
                s = "L";
                moves++;
            } else {
                s = "U";
                moves++;
            }
            k -= f;
            steps.push_back(make_pair(f, s));
        }

        cout << steps.size() << endl;
        for (auto step : steps) {
            cout << step.first << " " << step.second << endl;
        }
    }

    return 0;
}