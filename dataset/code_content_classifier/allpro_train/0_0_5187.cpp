#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> results;

int countArrangements(int player, int mask) {
    if (mask == (1 << N) - 1) {
        return 1;
    }

    int count = 0;
    for (int opponent = 0; opponent < N; opponent++) {
        if ((mask & (1 << opponent)) == 0 && results[opponent][player]) {
            count += countArrangements(opponent, mask | (1 << opponent));
        }
    }
    
    return count;
}

int main() {
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }

        results.clear();
        results.resize(N, vector<int>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> results[i][j];
            }
        }

        int totalArrangements = countArrangements(M - 1, 1 << (M - 1));
        cout << totalArrangements << endl;
    }

    return 0;
}