#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<int> A(H), B(W);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < W; i++) {
        cin >> B[i];
    }

    vector<vector<int>> C(H, vector<int>(W, 0));

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            int a, b, v;
            cin >> a >> b >> v;
            for (int j = a - 1; j <= b - 1; j++) {
                A[j] += v;
            }
        } else if (query == 2) {
            int c, d, v;
            cin >> c >> d >> v;
            for (int j = c - 1; j <= d - 1; j++) {
                B[j] += v;
            }
        } else if (query == 3) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int min_val = INT_MAX;
            pair<int, int> min_pos;
            for (int x = a - 1; x < b; x++) {
                for (int y = c - 1; y < d; y++) {
                    C[x][y] = A[x] * B[y];
                    if (C[x][y] < min_val) {
                        min_val = C[x][y];
                        min_pos = {x+1, y+1};
                    }
                }
            }
            cout << min_val << " " << min_pos.first * min_pos.second << endl;
        } else if (query == 4) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int max_val = INT_MIN;
            pair<int, int> max_pos;
            for (int x = a - 1; x < b; x++) {
                for (int y = c - 1; y < d; y++) {
                    C[x][y] = A[x] * B[y];
                    if (C[x][y] > max_val) {
                        max_val = C[x][y];
                        max_pos = {x+1, y+1};
                    }
                }
            }
            cout << max_val << " " << max_pos.first * max_pos.second << endl;
        }
    }

    return 0;
}