#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex {
    int parent;
    int gold;
    int price;
};

vector<Vertex> tree;

pair<int, int> dfs(int v, int w) {
    int gold_bought = 0;
    int money_spent = 0;

    while (v != 0) {
        int tons_to_buy = min(w, tree[v].gold);
        gold_bought += tons_to_buy;
        money_spent += tons_to_buy * tree[v].price;
        w -= tons_to_buy;
        tree[v].gold -= tons_to_buy;

        v = tree[v].parent;
    }

    return {gold_bought, money_spent};
}

int main() {
    int q, a0, c0;
    cin >> q >> a0 >> c0;

    tree.resize(q);
    tree[0] = {0, a0, c0};

    for (int i = 1; i < q; i++) {
        int type, p, a, c;
        cin >> type >> p >> a >> c;

        if (type == 1) {
            tree[i] = {p, a, c};
        } else {
            pair<int, int> result = dfs(p, a);
            cout << result.first << " " << result.second << endl;
        }
    }

    return 0;
}