#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> D(M), A(M), B(M);
    for(int i = 0; i < M; i++) {
        cin >> D[i] >> A[i] >> B[i];
    }

    while(Q--) {
        int E, S, T;
        cin >> E >> S >> T;

        bool canMove = false;
        // Check if AOR Ika-chan can move using stairs
        if(abs(S-T) <= E) {
            canMove = true;
        } else {
            // Check if AOR Ika-chan can move using elevators
            for(int i = 0; i < M; i++) {
                if(D[i] <= E && A[i] <= min(S, T) && B[i] >= max(S, T)) {
                    canMove = true;
                    break;
                }
            }
        }

        if(canMove) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}