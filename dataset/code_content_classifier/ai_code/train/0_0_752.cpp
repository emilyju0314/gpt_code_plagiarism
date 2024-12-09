#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N*N);
    for(int i = 0; i < N*N; i++) {
        cin >> P[i];
    }

    vector<vector<int>> pos(N*N, vector<int>(2));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            pos[P[i*N+j]-1] = {i, j};
        }
    }

    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> ans(N*N);
    for(int i = 0; i < N*N; i++) {
        int x = pos[i][0];
        int y = pos[i][1];
        for(int j = i+1; j < N*N; j++) {
            int nx = pos[j][0];
            int ny = pos[j][1];

            int min_steps = min(abs(x - nx), abs(y - ny));

            int dir;
            if(nx > x)
                dir = 0; // down
            else if(nx < x)
                dir = 1; // up
            else if(ny > y)
                dir = 2; // right
            else
                dir = 3; // left

            int cx = x + dirs[dir][0] * min_steps;
            int cy = y + dirs[dir][1] * min_steps;

            ans[i]++;
            ans[j]++;

            if(cx == nx && cy == ny)
                break;
        }
    }

    int total = 0;
    for(int i = 0; i < N*N; i++) {
        total += (ans[i] != 1);
    }

    cout << total << endl;

    return 0;
}