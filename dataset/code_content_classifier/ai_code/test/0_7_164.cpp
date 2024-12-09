#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> left_child;
vector<int> right_child;
vector<string> node_label;
vector<int> duplicate_count;

string in_order_traversal(int u) {
    if (u == 0) {
        return "";
    }

    string left = in_order_traversal(left_child[u]);
    string right = in_order_traversal(right_child[u]);

    return left + node_label[u] + right;
}

void update_duplicate_count(int u, bool parent_duplicated) {
    if (u == 0) {
        return;
    }

    if (parent_duplicated || duplicate_count[left_child[u]] > 0 || duplicate_count[right_child[u]] > 0) {
        duplicate_count[u] = 1;
    }

    update_duplicate_count(left_child[u], duplicate_count[u] > 0);
    update_duplicate_count(right_child[u], duplicate_count[u] > 0);
}

int main() {
    int n, k;
    cin >> n >> k;

    left_child.resize(n + 1);
    right_child.resize(n + 1);
    node_label.resize(n + 1);
    duplicate_count.resize(n + 1, 0);

    string initial_label;
    cin >> initial_label;
    for (int i = 1; i <= n; i++) {
        node_label[i] = initial_label[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        cin >> left_child[i] >> right_child[i];
    }

    update_duplicate_count(1, false);

    vector<pair<char, int>> label_indices;
    for (int i = 1; i <= n; i++) {
        label_indices.push_back({node_label[i], i});
    }

    sort(label_indices.begin(), label_indices.end());

    for (int i = 0; i < k; i++) {
        duplicate_count[label_indices[i].second] += 1;
    }

    update_duplicate_count(1, false);

    cout << in_order_traversal(1) << endl;

    return 0;
}