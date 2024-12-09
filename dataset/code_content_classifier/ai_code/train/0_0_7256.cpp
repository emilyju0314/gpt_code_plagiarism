#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> sequences(N, vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> sequences[i][j];
        }
    }

    int total_casts = 0;
    for(int j = 0; j < M; j++) {
        int prev_sum = 0;

        for(int i = 0; i < N; i++) {
            int current_sum = 0;
            for(int k = 0; k <= j; k++) {
                current_sum += sequences[i][k];
            }

            if(current_sum < prev_sum) {
                total_casts += (prev_sum - current_sum);
                sequences[i][j] += (prev_sum - current_sum);
            } else if(current_sum > prev_sum) {
                prev_sum = current_sum;
            }
        }

        if(sequences[N-1][j] != prev_sum) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << total_casts << endl;

    return 0;
}