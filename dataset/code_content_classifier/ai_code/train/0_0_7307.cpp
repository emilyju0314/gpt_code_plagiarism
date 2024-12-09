#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> slab(N);
    for (int i = 0; i < N; i++) {
        cin >> slab[i];
    }

    int repaints = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i + j) % 2 == 0 && slab[i][j] == 'B') {
                repaints++;
            } else if ((i + j) % 2 == 1 && slab[i][j] == 'W') {
                repaints++;
            }
        }
    }

    cout << repaints << endl;

    return 0;
}