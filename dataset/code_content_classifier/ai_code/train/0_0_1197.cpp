#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    vector<int> sorted_nums(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            sorted_nums[grid[i][j]-1] = i*M + j + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << sorted_nums[M*i + j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << sorted_nums[M*j + i] << " ";
        }
        cout << endl;
    }

    return 0;
}