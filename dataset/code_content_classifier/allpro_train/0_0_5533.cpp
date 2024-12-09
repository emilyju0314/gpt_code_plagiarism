#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int x, y, z;
};

vector<Node> readTree(int n) {
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].x >> nodes[i].y >> nodes[i].z;
    }
    return nodes;
}

vector<pair<int, int>> readEdges(int n) {
    vector<pair<int, int>> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    return edges;
}

bool checkTransformation(vector<Node>& tree1, vector<Node>& tree2, vector<pair<int, int>>& edges1, vector<pair<int, int>>& edges2) {
    sort(tree1.begin(), tree1.end(), [](const Node& a, const Node& b) {
       return make_tuple(a.x, a.y, a.z) < make_tuple(b.x, b.y, b.z); 
    });
    sort(tree2.begin(), tree2.end(), [](const Node& a, const Node& b) {
       return make_tuple(a.x, a.y, a.z) < make_tuple(b.x, b.y, b.z); 
    });

    vector<vector<int>> adj1(tree1.size());
    vector<vector<int>> adj2(tree2.size());

    for (auto& edge : edges1) {
        int u = edge.first - 1, v = edge.second - 1;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    for (auto& edge : edges2) {
        int u = edge.first - tree1.size() - 1, v = edge.second - tree1.size() - 1;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    auto doTransform = [](Node& node, char op, double arg) {
        if (op == 't') {
            if (arg < 0) {
                node.x += arg;
            } else {
                node.x -= arg;
            }
        } else if (op == 'r') {
            double newX, newY, newZ;
            if (arg == 'x') {
                newY = node.y * cos(arg) - node.z * sin(arg);
                newZ = node.y * sin(arg) + node.z * cos(arg);
                node.y = newY;
                node.z = newZ;
            } else if (arg == 'y') {
                newX = node.x * cos(arg) + node.z * sin(arg);
                newZ = -node.x * sin(arg) + node.z * cos(arg);
                node.x = newX;
                node.z = newZ;
            } else if (arg == 'z') {
                newX = node.x * cos(arg) - node.y * sin(arg);
                newY = node.x * sin(arg) + node.y * cos(arg);
                node.x = newX;
                node.y = newY;
            }
        } else if (op == 's') {
            node.x *= arg;
            node.y *= arg;
            node.z *= arg;
        }
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                char op1 = (i == 0 ? 't' : i == 1 ? 'r' : 's');
                char op2 = (j == 0 ? 't' : j == 1 ? 'r' : 's');
                char op3 = (k == 0 ? 't' : k == 1 ? 'r' : 's');
                double arg1 = (i == 2 ? sqrt(2) : M_PI / 2);
                double arg2 = M_PI / 4;
                double arg3 = sqrt(2);

                for (int idx = 0; idx < tree1.size(); idx++) {
                    Node cur1 = tree1[idx], cur2 = tree2[idx];

                    doTransform(cur1, op1, arg1);
                    doTransform(cur1, op2, arg2);
                    doTransform(cur1, op3, arg3);

                    if (abs(cur1.x - cur2.x) > 1e-7 || abs(cur1.y - cur2.y) > 1e-7 || abs(cur1.z - cur2.z) > 1e-7) {
                        goto next_iteration;
                    }
                }

                return true;
                next_iteration:;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree1 = readTree(n);
    vector<pair<int, int>> edges1 = readEdges(n);
    vector<Node> tree2 = readTree(n);
    vector<pair<int, int>> edges2 = readEdges(n);

    if (checkTransformation(tree1, tree2, edges1, edges2)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}