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
    
    for (int q = 0; q < Q; q++) {
        int L, R, D;
        cin >> L >> R >> D;
        
        bool possible = false;
        for (int i = L-1; i < R; i++) {
            if (cities[i] == D) {
                possible = true;
                break;
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