#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<pair<int, int>, int> icePieces;
    vector<int> counts(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        icePieces[{x, y}]++;
    }

    for (auto it = icePieces.begin(); it != icePieces.end(); it++) {
        int x = it->first.first;
        int y = it->first.second;
        int count = it->second;

        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                int currentCount = 0;
                for (auto ice : icePieces) {
                    int iceX = ice.first.first;
                    int iceY = ice.first.second;
                    if (iceX >= i && iceX < i + k && iceY >= j && iceY < j + k) {
                        currentCount += ice.second;
                    }
                }
                counts[currentCount]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << counts[i] << " ";
    }

    return 0;
}