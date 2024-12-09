struct Room {
    int powerConsumption;
    int turnOnCost;
    int turnOffCost;
};

int solveElectricPower(int R, int C, int M, vector<vector<char>>& layout, vector<vector<Room>>& roomCharacteristics, vector<pair<int, int>>& tasks) {
    // Initialize DP array
    vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(M, INT_MAX)));

    // Iterate through tasks
    for (int i = 0; i < M; i++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                // Calculate minimum electric power consumed at each step
            }
        }
    }

    // Find the minimum electric power consumed after finishing all tasks
    int minPowerConsumed = INT_MAX;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            minPowerConsumed = min(minPowerConsumed, dp[r][c][M - 1]);
        }
    }

    return minPowerConsumed;
}

int main() {
    int R, C, M;
    cin >> R >> C >> M;

    vector<vector<char>> layout(R, vector<char>(C));
    vector<vector<Room>> roomCharacteristics(R, vector<Room>(C));

    // Read layout and room characteristics matrices

    vector<pair<int, int>> tasks;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        tasks.push_back({x, y});
    }

    int result = solveElectricPower(R, C, M, layout, roomCharacteristics, tasks);
    cout << result << endl;

    return 0;
}