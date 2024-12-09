#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> cities(N);
    for(int i = 0; i < N; i++) {
        cin >> cities[i];
    }

    for(int i = 0; i < Q; i++) {
        int L, R, D;
        cin >> L >> R >> D;
        --L; --R;
        
        bool possible = false;
        for(int j = L; j != R; j = (j + 1) % N) {
            if(abs(cities[j] - cities[(j + 1) % N]) == D) {
                possible = true;
                break;
            }
        }

        if(possible) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}