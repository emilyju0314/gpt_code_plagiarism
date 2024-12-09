#include<bits/stdc++.h>
using namespace std;

int h, w;

bool isValid(int x, int y, vector<vector<int>>& image) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

void dfs(int x, int y, vector<vector<int>>& image, vector<vector<bool>>& visited) {
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY, image) && image[newX][newY] == 1 && !visited[newX][newY]) {
            dfs(newX, newY, image, visited);
        }
    }
}

pair<int, vector<int>> countSunsAndRays(vector<vector<int>>& image) {
    int suns = 0;
    vector<int> raysOnSuns;

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (image[i][j] == 1 && !visited[i][j]) {
                suns++;
                int rays = 0;

                dfs(i, j, image, visited);

                raysOnSuns.push_back(rays);
            }
        }
    }

    sort(raysOnSuns.begin(), raysOnSuns.end());
    
    return {suns, raysOnSuns};
}

int main() {
    cin >> h >> w;

    vector<vector<int>> image(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> image[i][j];
        }
    }

    pair<int, vector<int>> result = countSunsAndRays(image);

    cout << result.first << endl;

    for (int rays : result.second) {
        cout << rays << " ";
    }
    cout << endl;

    return 0;
}