#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    string S, T;
    cin >> S >> T;

    // Pre-calculate the cumulative distances in the east-west and north-south directions
    vector<int> distEW(N+1, 0);
    vector<int> distNS(M+1, 0);
    for (int i = 0; i < N; i++) {
        distEW[i+1] = distEW[i] + (S[i] == 'W' ? 1 : 0);
    }
    for (int i = 0; i < M; i++) {
        distNS[i+1] = distNS[i] + (T[i] == 'S' ? 1 : 0);
    }

    for (int q = 0; q < Q; q++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int distX = abs(distEW[a] - distEW[c]);
        int distY = abs(distNS[b] - distNS[d]);

        if ((S[a-1] == 'E' && c < a) || (S[a-1] == 'W' && c > a) || (T[b-1] == 'N' && d < b) || (T[b-1] == 'S' && d > b)) {
            cout << -1 << endl;
        } else {
            cout << distX + distY << endl;
        }
    }

    return 0;
}