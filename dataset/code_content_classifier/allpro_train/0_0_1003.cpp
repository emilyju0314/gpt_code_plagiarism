#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Node {
    int value;
    int count;
    long long potential;
};

vector<Node> tree;

void add(int v, int e) {
    int index = v - 1;
    tree[index].value += e;
}

long long decay(int h, int index) {
    if (index >= (1 << h) - 1) {
        return tree[index].value;
    } else {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        long long left_potential = decay(h, left) + tree[left].value;
        long long right_potential = decay(h, right) + tree[right].value;
        if (left_potential > right_potential) {
            tree[right].potential = left_potential - right_potential;
            return left_potential;
        } else {
            tree[left].potential = right_potential - left_potential;
            return right_potential;
        }
    }
}

int main() {
    int h, q;
    cin >> h >> q;

    int n = (1 << h) - 1;
    tree.resize(n);

    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;

        if (type == "add") {
            int v, e;
            cin >> v >> e;
            add(v, e);
        } else if (type == "decay") {
            decay(h, 0); // starting from the root
            cout << fixed << setprecision(8) << tree[0].potential << endl;
        }
    }

    return 0;
}