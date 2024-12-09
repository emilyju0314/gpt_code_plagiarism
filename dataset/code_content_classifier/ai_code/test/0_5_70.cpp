#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> cities(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < Q; i++) {
        int L, R, D;
        cin >> L >> R >> D;

        bool possible = false;
        for (int j = L - 1; j < R - 1; j++) {
            if ((cities[j] % (10^9+7)) == (cities[j+1] % (10^9+7))) {
                if (abs(cities[j] - cities[j+1]) % D == 0) {
                    possible = true;
                    break;
                }
            }
        }

        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}