#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int color;
    int sum;
    vector<pair<int, int>> edges;
};

int main() {
    int n;
    cin >> n;

    vector<Node> nodes(n);

    for (int i = 0; i < n; i++) {
        int color, sum;
        cin >> color >> sum;
        nodes[i].color = color;
        nodes[i].sum = sum;
    }

    int white_node = -1;
    int black_node = -1;
    for (int i = 0; i < n; i++) {
        if (nodes[i].color == 0) {
            white_node = i;
        } else {
            black_node = i;
        }
    }

    int white_idx = 1;
    int black_idx = 1;

    for (int i = 0; i < n; i++) {
        if (i != white_node && i != black_node) {
            if (nodes[i].color == 0) {
                nodes[i].edges.push_back({white_node, nodes[i].sum});
                nodes[white_node].edges.push_back({i, nodes[i].sum});
                white_idx++;
            } else {
                nodes[i].edges.push_back({black_node, nodes[i].sum});
                nodes[black_node].edges.push_back({i, nodes[i].sum});
                black_idx++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto edge : nodes[i].edges) {
            cout << i+1 << " " << edge.first+1 << " " << edge.second << "\n";
        }
    }

    return 0;
}