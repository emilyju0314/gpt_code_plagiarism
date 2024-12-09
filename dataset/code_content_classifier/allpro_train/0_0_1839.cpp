#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

int N, M, K, T, W;
int shipY, shipX;
vector<vector<char>> grid;
vector<string> wind;
vector<vector<int>> foodCoords;
map<pair<pair<int, int>, pair<int, int>>, int> foodSupply;
vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct State {
    int y, x, daysLeft, foodIndex;
};

vector<State> getNextStates(const State& state, const char& w) {
    vector<State> nextStates;
    for (pair<int, int> dir : directions) {
        int newY = state.y + dir.first;
        int newX = state.x + dir.second;
        if (newY >= 0 && newY < N && newX >= 0 && newX < M && grid[newY][newX] == 'S') {
            int newDaysLeft = state.daysLeft - 1;
            if (w != 'C') {
                if ((w == 'N' && dir == directions[0]) || (w == 'E' && dir == directions[1]) 
                    || (w == 'S' && dir == directions[2]) || (w == 'W' && dir == directions[3])) {
                    newY += dir.first;
                    newX += dir.second;
                }
            }
            if (newDaysLeft >= 0) {
                nextStates.push_back({newY, newX, newDaysLeft, state.foodIndex});
            }
        }
    }
    return nextStates;
}

int shortestPath() {
    vector<vector<vector<vector<bool>>> dp(N, vector<vector<vector<bool>>>(M, vector<vector<bool>>(K + 1, vector<bool>(T, false))));
    queue<State> q;
    q.push({shipY, shipX, K, 0});
    dp[shipY][shipX][K][0] = true;
    
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        if (grid[curr.y][curr.x] == 'P') {
            return W - curr.daysLeft;
        }
        
        for (int i = 0; i < W; i++) {
            vector<State> nextStates = getNextStates(curr, wind[i]);
            for (State nextState : nextStates) {
                if (nextState.daysLeft == K && foodSupply.find({{nextState.y, nextState.x}, i}) != foodSupply.end()) {
                    nextState.daysLeft += foodSupply[{{nextState.y, nextState.x}, i}];
                    nextState.foodIndex++;
                }
                if (!dp[nextState.y][nextState.x][nextState.daysLeft][nextState.foodIndex]) {
                    dp[nextState.y][nextState.x][nextState.daysLeft][nextState.foodIndex] = true;
                    q.push(nextState);
                }
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> N >> M;
    cin >> K >> T >> W;

    grid.resize(N);
    for (int y = 0; y < N; y++) {
        grid[y].resize(M);
        for (int x = 0; x < M; x++) {
            cin >> grid[y][x];
            if (grid[y][x] == 'M') {
                shipY = y;
                shipX = x;
            }
        }
    }

    for (int i = 0; i < W; i++) {
        char windDirection;
        cin >> windDirection;
        wind.push_back(string(1, windDirection));
    }

    for (int i = 0; i < T; i++) {
        int Y, X, F;
        cin >> Y >> X >> F;
        foodCoords.push_back({Y, X});
        foodSupply[{{Y, X}, i}] = F;
    }

    int result = shortestPath();
    cout << result << endl;

    return 0;
}