#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> parents;
vector<int> labels;
vector<int> operations;

void construct_bamboo_blank(int n) {
    for (int i = 0; i < n; i++) {
        labels.push_back(i);
    }
}

void perform_operation(int v) {
    int new_parent = parents[parents[v]];
    parents[v] = new_parent;
    operations.push_back(v);
}

void optimize_tree(int n) {
    stack<int> stk;
    vector<int> depths(n, 0);

    for (int i = 0; i < n; i++) {
        depths[i] = i;
        while (!stk.empty() && parents[i] != stk.top()) {
            stk.pop();
        }
        if (!stk.empty()) {
            depths[i] = max(depths[i], depths[stk.top()]);
        }
        stk.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (depths[i] != i) {
            perform_operation(i);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        parents.push_back(p);
    }

    construct_bamboo_blank(n);

    optimize_tree(n);

    for (int label : labels) {
        cout << label << " ";
    }
    cout << endl;

    cout << operations.size() << endl;

    for (int operation : operations) {
        cout << operation << " ";
    }
    cout << endl;

    return 0;
}