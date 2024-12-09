#include <iostream>
using namespace std;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    // Check if conditions can be satisfied
    if (2*A > W || 2*B > H) {
        cout << -1 << endl;
    } else {
        // Fill the squares
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if ((i < B && j < A) || (i >= B && j >= A)) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << endl;
        }
    }

    return 0;
}