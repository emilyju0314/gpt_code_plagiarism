#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    vector<vector<int>> roads(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        roads[A].push_back(B);
        roads[B].push_back(A);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool good = true;
        for(int j = 0; j < roads[i].size(); j++) {
            if(H[i] <= H[roads[i][j]]) {
                good = false;
                break;
            }
        }
        if(good) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}