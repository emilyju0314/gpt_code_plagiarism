#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int n, m, q;
vector<string> conveyorBelts;
vector<vector<bool>> visited;

void followBread(int x, int y) {
    while (x >= 1 && x <= n && y >= 1 && y <= m) {
        if (visited[x][y]) {
            cout << -1 << " " << -1 << endl;
            return;
        }
        visited[x][y] = true;
        
        char c = conveyorBelts[x-1][y-1];
        if (c == '>') {
            y++;
        } else if (c == '<') {
            y--;
        } else if (c == '^') {
            x--;
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    cin >> n >> m >> q;
    
    conveyorBelts.resize(n);
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> conveyorBelts[i];
    }

    for (int i = 0; i < q; i++) {
        char type;
        int x, y;
        cin >> type >> x >> y;

        if (type == 'A') {
            followBread(x, y);
        } else if (type == 'C') {
            char c;
            cin >> c;
            conveyorBelts[x-1][y-1] = c;
        }
    }

    return 0;
}