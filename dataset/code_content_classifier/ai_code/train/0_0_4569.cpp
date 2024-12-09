#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    bool possible = false;

    for(int row=0; row<=N; row++) {
        for(int col=0; col<=M; col++) {
            int black_squares = row * (M-col) + col * (N-row);
            if(black_squares == K) {
                possible = true;
                break;
            }
        }
    }

    if(possible) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}