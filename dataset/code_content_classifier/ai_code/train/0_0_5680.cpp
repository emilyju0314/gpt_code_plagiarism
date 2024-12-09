#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(2 * n - 1);
    vector<int> depth(2 * n - 1, 0);

    // Function to query LCA and return the result
    char query(int a, int b, int c) {
        cout << a << " " << b << " " << c << endl;
        char result;
        cin >> result;
        return result;
    }

    // Function to find the parent of the node given the LCA information
    int findParent(int a, int b, int c) {
        char res = query(a, b, c);
        if (res == 'X') {
            return a;
        } else if (res == 'Y') {
            return b;
        } else {
            return c;
        }
    }

    // Build the tree by querying LCA information
    int curNode = 2 * n - 1;
    for (int i = 0; i < n - 2; ++i) {
        int a = curNode - 2, b = curNode - 1, c = curNode;
        int parent = findParent(a, b, c);

        depth[parent] = depth[a] + 1;
        depth[a] = depth[parent] + 1;
        depth[b] = depth[parent] + 1;
        depth[c] = depth[parent] + 1;

        tree[parent].push_back(a);
        tree[parent].push_back(b);
        tree[parent].push_back(c);

        curNode -= 3;
    }

    // Output the parent-child relationships of the tree
    cout << -1 << endl;
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int child : tree[i]) {
            cout << i + 1 << " " << child + 1 << endl;
        }
    }

    cout.flush();

    return 0;
}