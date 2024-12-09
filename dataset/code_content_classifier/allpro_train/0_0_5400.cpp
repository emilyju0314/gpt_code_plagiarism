#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dressingRoom(n, vector<int>(m));
    vector<vector<int>> pairs(m * n / 2 + 1, vector<int>(2));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> dressingRoom[i][j];
            if(pairs[dressingRoom[i][j]][0] == 0) {
                pairs[dressingRoom[i][j]][0] = i;
                pairs[dressingRoom[i][j]][1] = j;
            } else {
                pairs[dressingRoom[i][j]].push_back(i);
                pairs[dressingRoom[i][j]].push_back(j);
            }
        }
    }

    int minMoves = 0;

    for(int k = 1; k < pairs.size(); k++) {
        int x1 = pairs[k][0];
        int y1 = pairs[k][1];
        int x2 = pairs[k][2];
        int y2 = pairs[k][3];

        minMoves += abs(x1 - x2) + abs(y1 - y2);
    }

    cout << minMoves << endl;

    return 0;
}