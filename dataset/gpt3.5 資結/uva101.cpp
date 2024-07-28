#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void move_onto(vector<vector<int>>& blocks, int a, int b) {
    // 将a上面的木块归位
    while (blocks[a].back() != a) {
        int top_block = blocks[a].back();
        blocks[top_block].push_back(top_block);
        blocks[a].pop_back();
    }
    // 将b上面的木块归位
    while (blocks[b].back() != b) {
        int top_block = blocks[b].back();
        blocks[top_block].push_back(top_block);
        blocks[b].pop_back();
    }
    // 将a放在b上面
    blocks[b].push_back(a);
    blocks[a].pop_back();
}

void move_over(vector<vector<int>>& blocks, int a, int b) {
    // 将a上面的木块归位
    while (blocks[a].back() != a) {
        int top_block = blocks[a].back();
        blocks[top_block].push_back(top_block);
        blocks[a].pop_back();
    }
    // 将a放在b上面
    blocks[b].push_back(a);
    blocks[a].pop_back();
}

void pile_onto(vector<vector<int>>& blocks, int a, int b) {
    // 将b上面的木块归位
    while (blocks[b].back() != b) {
        int top_block = blocks[b].back();
        blocks[top_block].push_back(top_block);
        blocks[b].pop_back();
    }
    // 将a及以上的木块一起移动到b上
    vector<int> pile_blocks;
    while (blocks[a].back() != a) {
        pile_blocks.push_back(blocks[a].back());
        blocks[a].pop_back();
    }
    pile_blocks.push_back(a);
    for (int block : pile_blocks) {
        blocks[b].push_back(block);
    }
}

void pile_over(vector<vector<int>>& blocks, int a, int b) {
    // 将a及以上的木块一起移动到b上
    vector<int> pile_blocks;
    while (blocks[a].back() != a) {
        pile_blocks.push_back(blocks[a].back());
        blocks[a].pop_back();
    }
    pile_blocks.push_back(a);
    for (int block : pile_blocks) {
        blocks[b].push_back(block);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> blocks(n);
    for (int i = 0; i < n; i++) {
        blocks[i].push_back(i);
    }

    string action, on;
    while (cin >> action) {
        if (action == "quit") {
            break;
        }

        int a, b;
        cin >> a >> on >> b;

        if (a == b || blocks[a].back() == blocks[b].back()) {
            continue;
        }

        if (action == "move" && on == "onto") {
            move_onto(blocks, a, b);
        }
        else if (action == "move" && on == "over") {
            move_over(blocks, a, b);
        }
        else if (action == "pile" && on == "onto") {
            pile_onto(blocks, a, b);
        }
        else if (action == "pile" && on == "over") {
            pile_over(blocks, a, b);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int block : blocks[i]) {
            cout << " " << block;
        }
        cout << endl;
    }

    return 0;
}