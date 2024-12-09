#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> construction;
vector<vector<bool>> visited;
int room_size;

void find_room_size(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || construction[x][y] != 15) {
        return;
    }

    visited[x][y] = true;
    room_size++;

    find_room_size(x + 1, y);
    find_room_size(x - 1, y);
    find_room_size(x, y + 1);
    find_room_size(x, y - 1);
}

int main() {
    cin >> n >> m;

    construction.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> construction[i][j];
        }
    }

    vector<int> room_sizes;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                room_size = 0;
                find_room_size(i, j);
                room_sizes.push_back(room_size);
            }
        }
    }

    sort(room_sizes.rbegin(), room_sizes.rend());

    for (int size : room_sizes) {
        cout << size << " ";
    }

    return 0;
}