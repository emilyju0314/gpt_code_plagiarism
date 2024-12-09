#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    vector<int> max_row(H, 0);
    vector<int> max_col(W, 0);

    for (int i = 0; i < N; i++) {
        int r, c, a;
        cin >> r >> c >> a;
        r--;
        c--;

        max_row[r] = max(max_row[r], a);
        max_col[c] = max(max_col[c], a);
    }

    int sum = 0;
    for (int i = 0; i < H; i++) {
        sum += max_row[i];
    }
    for (int i = 0; i < W; i++) {
        sum += max_col[i];
    }

    cout << sum << endl;

    return 0;
}