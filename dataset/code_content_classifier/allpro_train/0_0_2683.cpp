#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> a(N);
    vector<vector<int>> b(M, vector<int>(N));
    vector<int> T(M);

    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> b[i][j];
        }
    }

    for(int i=0; i<M; i++) {
        cin >> T[i];
    }

    int totalScore = 0;

    for(int i=0; i<N; i++) {
        int maxScore = 0;

        for(int j=0; j<M; j++) {
            if(T[j] > 0) {
                maxScore = max(maxScore, b[j][i]);
                T[j]--;
            }
        }

        if(maxScore == 0) {
            maxScore = a[i];
        }

        totalScore += maxScore;
    }

    cout << totalScore << endl;

    return 0;
}