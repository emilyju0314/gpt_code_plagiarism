#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string U;
    cin >> U;

    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> fears(M, vector<int>(3));
    for(int i=0; i<M; i++) {
        cin >> fears[i][0] >> fears[i][1] >> fears[i][2];
    }

    int total_fear = 0;
    for(int i=0; i<N; i++) {
        vector<int> left_fear(N), right_fear(N);
        for(int j=i-1; j>=0; j--) {
            if(U[j] == 'R') {
                left_fear[j] = left_fear[j+1] + A[j];
            } else {
                left_fear[j] = left_fear[j+1];
            }
        }
        for(int j=i+1; j<N; j++) {
            if(U[j] == 'L') {
                right_fear[j] = right_fear[j-1] + A[j];
            } else {
                right_fear[j] = right_fear[j-1];
            }
        }

        for(int j=0; j<M; j++) {
            if((U[fears[j][0] - 1] == 'L' && U[fears[j][1] - 1] == 'R') || (U[fears[j][0] - 1] == 'R' && U[fears[j][1] - 1] == 'L')) {
                total_fear += min(left_fear[fears[j][0]-1], right_fear[fears[j][1]-1]) * fears[j][2];
            }
        }
    }

    cout << total_fear << endl;

    return 0;
}