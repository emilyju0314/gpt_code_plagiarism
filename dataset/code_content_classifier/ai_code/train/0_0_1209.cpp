#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }

        vector<pair<int, int>> squares(N);
        squares[0] = make_pair(0, 0);

        int maxWidth = 1, maxHeight = 1;
        
        for (int i = 1; i < N; i++) {
            int ni, di;
            cin >> ni >> di;

            int x = squares[ni].first;
            int y = squares[ni].second;

            if (di == 0) {
                squares[i] = make_pair(x - 1, y);
                maxWidth = max(maxWidth, abs(x - 1) + 1);
            } else if (di == 1) {
                squares[i] = make_pair(x, y - 1);
                maxHeight = max(maxHeight, abs(y - 1) + 1);
            } else if (di == 2) {
                squares[i] = make_pair(x + 1, y);
                maxWidth = max(maxWidth, abs(x + 1) + 1);
            } else {
                squares[i] = make_pair(x, y + 1);
                maxHeight = max(maxHeight, abs(y + 1) + 1);
            }
        }
        cout << maxWidth << " " << maxHeight << endl;
    }
    return 0;
}