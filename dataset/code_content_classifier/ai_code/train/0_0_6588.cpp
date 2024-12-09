#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int c = 0;
    vector<pair<int, int>> moves;

    for (int i = 0; i < n; i++) {
        int diff = abs(a[i] - b[i]);
        if (diff > 5) {
            diff = 10 - diff;
            moves.push_back({i, a[i] > b[i] ? -1 : 1});
            if (i < n-1) {
                a[i+1] = ((a[i+1] - '0' + 10 + moves.back().second) % 10) + '0';
            }
            c++;
        }
        moves.push_back({i, a[i] > b[i] ? -1 : 1});
        a[i] = (a[i] - '0' + diff * moves.back().second) % 10 + '0';
        c++;
    }

    cout << c << endl;

    for (int i = 0; i < min(c, 100000); i++) {
        cout << moves[i].first + 1 << " " << (moves[i].second == -1 ? "-" : "+") << endl;
    }

    return 0;
}