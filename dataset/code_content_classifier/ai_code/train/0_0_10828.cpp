#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int color1;
    int value;
    int color2;
};

bool compareBlocks(Block a, Block b) {
    return a.value > b.value;
}

bool canConnect(Block a, Block b) {
    return (a.color2 == b.color1) || (a.color2 == b.color1 && a.color1 == b.color2);
}

int main() {
    int n;
    cin >> n;

    vector<Block> blocks(n);
    for(int i = 0; i < n; i++) {
        cin >> blocks[i].color1 >> blocks[i].value >> blocks[i].color2;
    }

    sort(blocks.begin(), blocks.end(), compareBlocks);

    int maxSum = 0;

    for(int i = 0; i < n; i++) {
        vector<bool> used(n);
        int sum = blocks[i].value;

        for(int j = i+1; j < n; j++) {
            if(!used[j] && canConnect(blocks[i], blocks[j])) {
                sum += blocks[j].value;
                used[j] = true;
            }
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
}