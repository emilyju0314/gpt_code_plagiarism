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

    sort(cities.begin(), cities.end());

    for (int i = 0; i < Q; i++) {
        int L, R, D;
        cin >> L >> R >> D;

        int dis = cities[R-1] - cities[L-1];
        if (dis % D == 0 || (dis + D) % (10e9 + 7) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}