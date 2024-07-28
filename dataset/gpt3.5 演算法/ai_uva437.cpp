#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Block {
    int l, w, h;

    Block(int l, int w, int h) : l(l), w(w), h(h) {}

    bool operator < (const Block& b) const {
        return l < b.l;
    }
};

int solve(vector<Block>& blocks) {
    // 生成所有可能的排列組合
    vector<Block> allBlocks;
    for (auto& b : blocks) {
        allBlocks.push_back(b);
        allBlocks.push_back(Block(b.l, b.h, b.w));
        allBlocks.push_back(Block(b.w, b.l, b.h));
        allBlocks.push_back(Block(b.w, b.h, b.l));
        allBlocks.push_back(Block(b.h, b.l, b.w));
        allBlocks.push_back(Block(b.h, b.w, b.l));
    }

    // 根據長排序
    sort(allBlocks.begin(), allBlocks.end());

    // 定義dp陣列，dp[i]代表以第i塊木塊結尾的最大高度
    vector<int> dp(allBlocks.size(), 0);

    int res = 0;
    for (int i = 0; i < allBlocks.size(); ++i) {
        dp[i] = allBlocks[i].h;
        for (int j = 0; j < i; ++j) {
            if (allBlocks[i].l > allBlocks[j].l && allBlocks[i].w > allBlocks[j].w) {
                dp[i] = max(dp[i], dp[j] + allBlocks[i].h);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    int t = 1; // 測試案例數
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<Block> blocks;
        for (int i = 0; i < n; ++i) {
            int l, w, h;
            cin >> l >> w >> h;
            blocks.push_back(Block(l, w, h));
            blocks.push_back(Block(w, h, l));
            blocks.push_back(Block(h, l, w));
        }

        int res = solve(blocks);
        cout << "Case " << t++ << ": maximum height = " << res << endl;
    }

    return 0;
}
