#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<char, int>> cards(n);
    vector<bool> present(52, false);

    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;
        present[(cards[i].first - 'A') * 13 + cards[i].second - 1] = true;
    }

    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            if (!present[s * 13 + r]) {
                cout << (char)('A' + s) << " " << r + 1 << endl;
            }
        }
    }

    return 0;
}