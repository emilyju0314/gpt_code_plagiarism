#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    string squares;
    cin >> squares;

    vector<pair<char, char>> spells(Q);
    for (int i = 0; i < Q; i++) {
        cin >> spells[i].first >> spells[i].second;
    }

    int left = 0, right = N - 1;
    while (left < right) {
        bool moved = false;
        for (int i = 0; i < Q; i++) {
            char t = spells[i].first;
            char d = spells[i].second;

            if (squares[left] == t && d == 'L') {
                if (left > 0) {
                    left--;
                    moved = true;
                }
            }
            if (squares[right] == t && d == 'R') {
                if (right < N - 1) {
                    right++;
                    moved = true;
                }
            }
        }
        if (!moved) {
            break;
        }
    }

    cout << right - left + 1 << endl;

    return 0;
}