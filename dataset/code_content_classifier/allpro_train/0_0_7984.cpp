#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string initial;
    cin >> initial;

    vector<int> moves;
    vector<int> positions;
    for (int i = 0; i < n - 1; ++i) {
        if (initial[i] == 'R' && initial[i + 1] == 'L') {
            moves.push_back(i);
            positions.push_back(i + 1);
        }
    }

    if (moves.size() > k || k > n) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < moves.size(); ++i) {
            if (k - moves.size() + 1 <= 0) {
                cout << 1 << " " << positions[i] << endl;
            } else {
                cout << 2 << " " << moves[i] + 1 << " " << positions[i] << endl;
            }
        }

        for (int i = 0; i < k - moves.size(); ++i) {
            cout << 1 << " " << i + 1 << endl;
        }
    }

    return 0;
}