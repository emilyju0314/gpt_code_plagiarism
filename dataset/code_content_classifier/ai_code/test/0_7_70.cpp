#include <iostream>
#include <vector>

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

        int distance = (cities[R-1] - cities[L-1] + cities.size()) % cities.size();
        if (distance % D == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}