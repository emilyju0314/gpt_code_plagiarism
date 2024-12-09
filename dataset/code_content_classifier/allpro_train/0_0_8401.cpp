#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    int total_rescues = 0;
    for(int i1 = 0; i1 < H; i1++) {
        for(int j1 = 0; j1 < W; j1++) {
            for(int i2 = i1; i2 < H; i2++) {
                for(int j2 = j1; j2 < W; j2++) {
                    for(int i = i1; i <= i2; i++) {
                        for(int j = j1; j <= j2; j++) {
                            total_rescues += A[i][j];
                        }
                    }
                }
            }
        }
    }

    cout << total_rescues << endl;

    return 0;
}