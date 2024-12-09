#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> A[i];
    }

    vector<vector<int>> B(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < M; i++) {
        int current_happiness = 0;
        int current_distance = 0;
        for(int j = 0; j < N-1; j++) {
            current_distance += A[j];
            int max_deliciousness = 0;
            for(int k = 0; k < M; k++) {
                int new_deliciousness = B[(i + j)%N][k];
                max_deliciousness = max(max_deliciousness, new_deliciousness);
            }
            current_happiness += max_deliciousness;
            ans = max(ans, current_happiness - current_distance);
        }
    }

    cout << ans << endl;

    return 0;
}