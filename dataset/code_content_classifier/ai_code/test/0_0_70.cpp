#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> cities(N);
    for(int i = 0; i < N; i++) {
        cin >> cities[i];
    }

    while(Q--) {
        int L, R, D;
        cin >> L >> R >> D;

        bool possible = false;
        int prev_city = cities[(R-1) % N];
        for(int i = R; i != L; i = (i-1+N) % N) {
            if(cities[i] == (prev_city - D + N) % N) {
                possible = true;
                break;
            }
            prev_city = cities[i];
        }

        if(possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}