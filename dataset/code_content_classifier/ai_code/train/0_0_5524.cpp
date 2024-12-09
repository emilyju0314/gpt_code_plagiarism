#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    vector<int> count(M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N; i++) {
            count[A[i][j] - 1]++;
            break;
        }
    }

    int max_count = *max_element(count.begin(), count.end());
    cout << max_count << endl;

    return 0;
}