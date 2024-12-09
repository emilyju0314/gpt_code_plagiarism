#include <iostream>
#include <vector>

using namespace std;

int solveTest(int n, int T, int a, int b, vector<int>& types, vector<int>& times) {
    int easySolved = 0, hardSolved = 0;
    int points = 0;
    vector<pair<int, int>> problems;

    for (int i = 0; i < n; i++) {
        problems.push_back(make_pair(times[i], types[i]));
        if (types[i] == 0) {
            easySolved++;
        } else {
            hardSolved++;
        }
    }

    int s = 0;

    for (int i = 0; i < n; i++) {
        if (problems[i].second == 0) {
            if (problems[i].first <= s) {
                points++;
            }
        } else {
            if (problems[i].first <= s) {
                if (easySolved > 0) {
                    easySolved--;
                    points++;
                    s += a;
                } else {
                    s += b;
                }
            } else {
                s += b - a;
            }
        }

        if (s > T) {
            break;
        }
    }

    return points;
}

int main() {
    int m;
    cin >> m;

    for (int k = 0; k < m; k++) {
        int n, T, a, b;
        cin >> n >> T >> a >> b;

        vector<int> types(n), times(n);
        for (int i = 0; i < n; i++) {
            cin >> types[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> times[i];
        }

        cout << solveTest(n, T, a, b, types, times) << endl;
    }

    return 0;
}