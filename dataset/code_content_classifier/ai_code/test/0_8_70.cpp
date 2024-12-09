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
        if (D == 0) {
            possible = true;
        } else {
            bool foundL = find(cities.begin(), cities.end(), cities[L-1]) != find(cities.begin(), cities.end(), cities[(L+1)%N]);
            bool foundR = find(cities.begin(), cities.end(), cities[R-1]) != find(cities.begin(), cities.end(), cities[(R+1)%N]);
            possible = foundL && foundR;
        }

        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}