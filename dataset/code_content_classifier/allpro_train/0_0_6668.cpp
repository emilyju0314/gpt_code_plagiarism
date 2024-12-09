#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int MAXX = 1 << 20;

struct Node {
    int left, right;
    int val;
    int lazy;

    Node() : left(0), right(0), val(0), lazy(0) {}
};

vector<Node> tree(4 * MAXN);
vector<int> arr(MAXN);

void build(int node, int left, int right) {
    tree[node].left = left;
    tree[node].right = right;
    tree[node].lazy = 0;

    if (left == right) {
        tree[node].val = arr[left];
    } else {
        int mid = (left + right) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);

        tree[node].val = tree[node * 2].val | tree[node * 2 + 1].val;
    }
}

void push(int node) {
    if (tree[node].left != tree[node].right) {
        tree[node * 2].lazy |= tree[node].lazy;
        tree[node * 2 + 1].lazy |= tree[node].lazy;
    }

    tree[node].val |= tree[node].lazy;
    tree[node].lazy = 0;
}

void update(int node, int index, int val) {
    if (tree[node].left == tree[node].right) {
        tree[node].val = val;
    } else {
        push(node);
        int mid = (tree[node].left + tree[node].right) / 2;

        if (index <= mid) {
            update(node * 2, index, val);
        } else {
            update(node * 2 + 1, index, val);
        }

        tree[node].val = tree[node * 2].val | tree[node * 2 + 1].val;
    }
}

void updateRange(int node, int left, int right, int val) {
    push(node);
    if (tree[node].left > right || tree[node].right < left) {
        return;
    }
    
    if (left <= tree[node].left && tree[node].right <= right) {
        tree[node].lazy |= val;
        push(node);
    } else {
        updateRange(node * 2, left, right, val);
        updateRange(node * 2 + 1, left, right, val);

        tree[node].val = tree[node * 2].val | tree[node * 2 + 1].val;
    }
}

int query(int node, int left, int right, int x) {
    if (tree[node].left > right || tree[node].right < left) {
        return 0;
    }

    push(node);
    if (left <= tree[node].left && tree[node].right <= right) {
        return (tree[node].val >= x);
    }

    return query(node * 2, left, right, x) + query(node * 2 + 1, left, right, x);
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, val;
            cin >> index >> val;
            update(1, index, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, l, r, x) << "\n";
        }
    }

    return 0;
}