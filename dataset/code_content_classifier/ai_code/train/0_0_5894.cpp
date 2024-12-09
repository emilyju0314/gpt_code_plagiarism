#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void queryAndAnswer(int n) {
    string colors(n, '1');
    for (int i = 1; i < n; ++i) {
        cout << "Q 1 " << i << " " << i + 1 << endl;
        cin >> colors[i];
    }

    vector<int> piles[3];
    for (int i = 0; i < n; ++i) {
        piles[colors[i] - '0'].push_back(i + 1);
    }

    cout << "A " << piles[0].size() << " " << piles[1].size() << " " << piles[2].size() << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j : piles[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    fflush(stdout);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        queryAndAnswer(n);
    }

    return 0;
}