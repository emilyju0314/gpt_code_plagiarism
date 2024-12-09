#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, T, Q;
    cin >> H >> W >> T >> Q;

    vector<vector<int>> taiyaki(H, vector<int>(W, 0));
    vector<pair<int, int>> events;

    for (int i = 0; i < Q; i++) {
        int t, c, h1, w1, h2, w2;
        cin >> t >> c >> h1 >> w1;
        
        if (c == 0) {
            taiyaki[h1-1][w1-1] = t + T;
        } else if (c == 1) {
            if (taiyaki[h1-1][w1-1] != 0 && taiyaki[h1-1][w1-1] <= t) {
                taiyaki[h1-1][w1-1] = 0;
            }
        } else {
            cin >> h2 >> w2;
            events.push_back({t, h1, w1, h2, w2});
        }
    }

    for (auto event : events) {
        int baked = 0;
        int unbaked = 0;
        for (int i = event.first; i < event.first + T; i++) {
            for (int h = event.second - 1; h <= event.fourth - 1; h++) {
                for (int w = event.third - 1; w <= event.fifth - 1; w++) {
                    if (taiyaki[h][w] != 0 && taiyaki[h][w] <= i) {
                        baked++;
                    } else if (taiyaki[h][w] == 0) {
                        unbaked++;
                    }
                }
            }
        }
        cout << baked << " " << unbaked << endl;
    }

    return 0;
}