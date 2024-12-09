#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    long long x, y;
};

long long distance(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    long long x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;

    long long xs, ys, t;
    cin >> xs >> ys >> t;

    vector<Node> nodes;
    nodes.push_back({x0, y0});

    Node last_node = {x0, y0};
    while (true) {
        Node next_node = {ax * last_node.x + bx, ay * last_node.y + by};
        if (next_node.x > 1e16 || next_node.y > 1e16) {
            break;
        }
        nodes.push_back(next_node);
        last_node = next_node;
    }

    int num_nodes = nodes.size();
    int max_data_nodes = 0;

    for (int i = 0; i < num_nodes; i++) {
        Node start = nodes[i];
        int collected = 0;
        long long time_left = t - distance({xs, ys}, start);

        if (time_left >= 0) {
            collected = 1;
            time_left -= distance(start, {xs, ys});

            for (int j = i + 1; j < num_nodes; j++) {
                time_left -= distance(start, nodes[j]);
                if (time_left >= 0) {
                    start = nodes[j];
                    collected++;
                } else {
                    break;
                }
            }

            max_data_nodes = max(max_data_nodes, collected);
        }
    }

    cout << max_data_nodes << endl;

    return 0;
}