#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int weight, solidness, value;
};

int main() {
    int N;
    cin >> N;

    vector<Block> blocks(N);
    for(int i = 0; i < N; i++) {
        cin >> blocks[i].weight >> blocks[i].solidness >> blocks[i].value;
    }

    sort(blocks.begin(), blocks.end(), [](const Block& b1, const Block& b2) {
        return b1.solidness < b2.solidness;
    });

    vector<long long> dp(10001, 0);
    for(int i = 0; i < N; i++) {
        for(int j = blocks[i].solidness; j >= blocks[i].weight; j--) {
            dp[j] = max(dp[j], dp[j - blocks[i].weight] + blocks[i].value);
        }
    }

    long long max_value = 0;
    for(int i = 0; i <= 10000; i++) {
        max_value = max(max_value, dp[i]);
    }

    cout << max_value << endl;

    return 0;
}