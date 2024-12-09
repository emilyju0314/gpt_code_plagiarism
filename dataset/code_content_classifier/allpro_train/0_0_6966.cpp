#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int h, q;
    cin >> h >> q;

    vector<pair<int, pair<int, int>>> questions(q);

    for (int i = 0; i < q; i++) {
        int level, L, R, ans;
        cin >> level >> L >> R >> ans;
        
        questions[i] = make_pair(level, make_pair(L, R));
    }

    int exitNode = -1;
    for (int exit = 1; exit <= (1 << h) - 1; exit++) {
        bool valid = true;
        for (auto [level, range] : questions) {
            int ancestor = exit;
            for (int i = h - level; i > 0; i--) {
                ancestor = (ancestor + 1) / 2;
            }

            int L = range.first;
            int R = range.second;

            if (!((ancestor >= L && ancestor <= R) == (ans == 1))) {
                valid = false;
                break;
            }
        }

        if (valid) {
            if (exitNode == -1) {
                exitNode = exit;
            } else {
                cout << "Data not sufficient!" << endl;
                return 0;
            }
        }
    }

    if (exitNode == -1) {
        cout << "Game cheated!" << endl;
    } else {
        cout << exitNode << endl;
    }

    return 0;
}