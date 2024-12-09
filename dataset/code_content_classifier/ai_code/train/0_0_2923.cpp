#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W;
    cin >> N;

    vector<int> a(N);

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int color = 1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int k = 0; k < a[color-1]; k++) {
                cout << color << " ";
                if((j + 1) == W) {
                    color++;
                    if(color > N) color = N;
                }
                j++;
            }
        }
        cout << endl;
    }

    return 0;
}