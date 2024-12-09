#include <iostream>
#include <vector>

using namespace std;

int main() {
    int W, H;
    cin >> W >> H;

    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    int count = 0;
    int pos = 0;
    for (int i = 0; i < N; i++) {
        if (p[i] == 0) {
            if ((pos % (2*W + 2*H - 4) < W - 1) || ((pos % (2*W + 2*H - 4) >= W + H) && (pos % (2*W + 2*H - 4) < 2*W + H - 1))) {
                count++;
            }
            pos++;
        } else {
            if ((pos % (2*W + 2*H - 4) < W + H - 1) && (pos % (2*W + 2*H - 4) >= W - 1)) {
                count++;
            }
            pos++;
        }
    }

    cout << count << endl;

    return 0;
}