#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> first_map(N);
    vector<string> second_map(M);

    for (int i = 0; i < N; i++) {
        cin >> first_map[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> second_map[i];
    }

    // Compare each M x M section of the first map with each M x M section of the second map
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            bool found = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (first_map[i + k][j + l] != second_map[l][k]) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }
            if (found) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}