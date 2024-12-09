#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> matrix;
int width, height;
bool visited[70][70] = { false };
string secret = "";

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < height && y < width && matrix[x][y] >= '0' && matrix[x][y] <= '9' && !visited[x][y];
}

void dfs(int x, int y, string curr) {
    visited[x][y] = true;
    curr += matrix[x][y];
    secret = max(secret, curr);

    int dx[] = {0, 1};
    int dy[] = {1, 0};

    for (int i = 0; i < 2; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY)) {
            dfs(newX, newY, curr);
        }
    }

    visited[x][y] = false;
}

int main() {
    while (true) {
        cin >> width >> height;
        if (width == 0 && height == 0) {
            break;
        }

        matrix.clear();
        secret = "";

        for (int i = 0; i < height; i++) {
            string row;
            cin >> row;
            matrix.push_back(row);
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] >= '0' && matrix[i][j] <= '9') {
                    dfs(i, j, "");
                }
            }
        }

        cout << secret << endl;
    }

    return 0;
}