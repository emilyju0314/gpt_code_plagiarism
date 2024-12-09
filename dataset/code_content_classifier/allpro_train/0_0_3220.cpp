#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int n, m;
vector<string> board;
unordered_set<long long> unique_photos;

long long hash_pair(int i, int j) {
    return i * n + j;
}

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '.') {
        return;
    }
    
    unique_photos.insert(hash_pair(i, j));
    char dir = board[i][j];
    
    if (dir == 'U') {
        dfs(i-1, j);
    } else if (dir == 'D') {
        dfs(i+1, j);
    } else if (dir == 'L') {
        dfs(i, j-1);
    } else if (dir == 'R') {
        dfs(i, j+1);
    }
}

int main() {
    cin >> n >> m;
    
    board.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != '.') {
                unique_photos.clear();
                dfs(i, j);
                cout << unique_photos.size() << endl;
            }
        }
    }
    
    return 0;
}