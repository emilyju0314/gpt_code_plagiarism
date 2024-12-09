#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> l(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
    }

    vector<int> max_souvenirs(M + 1, 0);

    for (int d = 1; d <= M; d++) {
        vector<int> souvenirs(M + 1, 0);
        
        for (int i = 0; i < N; i++) {
            for (int station = l[i]; station <= r[i]; station++) {
                if (station % d == 0) {
                    souvenirs[station]++;
                }
            }
        }

        for (int station = 0; station <= M; station++) {
            max_souvenirs[station] = max(max_souvenirs[station], souvenirs[station]);
        }
    }

    for (int i = 1; i <= M; i++) {
        cout << max_souvenirs[i] << endl;
    }

    return 0;
}