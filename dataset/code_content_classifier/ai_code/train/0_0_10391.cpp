#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<int>> land(H, vector<int>(W));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> land[i][j];
        }
    }

    int total = H * W;
    int min_price = 1e9;

    for(int i = 0; i < (1 << total); i++) {
        vector<int> prices(N, 0);

        for(int j = 0; j < total; j++) {
            if(i & (1 << j)) {
                prices[j % N] += land[j / W][j % W];
            }
        }

        int max_price = *max_element(prices.begin(), prices.end());
        min_price = min(min_price, max_price);
    }

    cout << min_price << endl;

    return 0;
}