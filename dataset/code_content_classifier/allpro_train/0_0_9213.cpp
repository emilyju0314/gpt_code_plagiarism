#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;

    vector<pair<int, int>> steps; // a pair of (left, right) spies watched in each step
    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        steps.push_back({l, r});
    }

    string output = "";
    if (s < f) {
        while (s != f) {
            if (s + 1 == f || (s == n && f == 1)) {
                break;
            }
            bool can_move_right = true;
            for (auto step : steps) {
                if (step.first <= s && step.second >= s) {
                    can_move_right = false;
                    break;
                }
            }
            if (can_move_right) {
                output += "R";
                s++;
            } else {
                output += "X";
            }
        }
    } else {
        while (s != f) {
            if (s - 1 == f || (s == 1 && f == n)) {
                break;
            }
            bool can_move_left = true;
            for (auto step : steps) {
                if (step.first <= s && step.second >= s) {
                    can_move_left = false;
                    break;
                }
            }
            if (can_move_left) {
                output += "L";
                s--;
            } else {
                output += "X";
            }
        }
    }

    for (int i = 0; i < m - output.size(); i++) {
        output += "X";
    }

    cout << output << endl;

    return 0;
}