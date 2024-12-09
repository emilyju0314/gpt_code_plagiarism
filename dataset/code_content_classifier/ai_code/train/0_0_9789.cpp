#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<int> A(H);
    vector<int> B(W);

    for(int i = 0; i < H; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < W; i++) {
        cin >> B[i];
    }

    int max_blocks = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int blocks = A[i] + B[j];
            if(blocks > max_blocks) {
                max_blocks = blocks;
            }
        }
    }

    cout << max_blocks << endl;

    return 0;
}