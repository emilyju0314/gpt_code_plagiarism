#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i].first >> dominoes[i].second;
    }

    int q;
    cin >> q;

    for (int t = 0; t < q; t++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        int currentX = dominoes[x].first;
        int currentLength = dominoes[x].second;
        bool possible = true;
        for (int i = x + 1; i <= y; i++) {
            int nextX = dominoes[i].first;
            int nextLength = dominoes[i].second;

            if (nextX <= currentX + currentLength) {
                currentX = nextX;
                currentLength = max(currentLength, nextX + nextLength - currentX);
            } else {
                possible = false;
                break;
            }
        }

        if (possible && currentX + currentLength >= dominoes[y].first) {
            cout << "0\n";
        } else {
            cout << dominoes[y].first - (currentX + currentLength) << "\n";
        }
    }

    return 0;
}