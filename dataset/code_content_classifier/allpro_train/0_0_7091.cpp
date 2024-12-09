#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        int N, M, P;
        cin >> N >> M >> P;
        if (N == 0 && M == 0 && P == 0) {
            break;
        }
        
        vector<int> votes(N);
        int total_votes = 0;
        for (int i = 0; i < N; i++) {
            cin >> votes[i];
            total_votes += votes[i];
        }

        if (total_votes == 0 || votes[M - 1] == 0) {
            cout << "0" << endl;
        } else {
            int dividend = (100 - P) * total_votes / votes[M - 1];
            cout << dividend << endl;
        }
    }

    return 0;
}