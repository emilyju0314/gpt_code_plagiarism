#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Node {
    int parent;
    int key;
    int left;
    int right;
};

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n + 1);
    for (int i = 1; i <= n; i++) {
        int parent, key;
        cin >> parent >> key;
        tree[i].parent = parent;
        tree[i].key = key;
    }

    // Construct the binary search tree
    for (int i = 1; i <= n; i++) {
        if (tree[i].parent == -1) continue;
        if (tree[i].key < tree[tree[i].parent].key) {
            tree[tree[i].parent].left = i;
        } else {
            tree[tree[i].parent].right = i;
        }
    }

    int k;
    cin >> k;

    vector<int> search_keys(k);
    for (int i = 0; i < k; i++) {
        cin >> search_keys[i];
    }

    // Calculate the expectation for each search key
    for (int key : search_keys) {
        double expectation = 0.0;

        for (int i = 1; i <= n; i++) {
            vector<int> path;
            int current = i;
            while (current != -1) {
                path.push_back(current);
                if (tree[current].key > key) {
                    current = tree[current].left;
                } else if (tree[current].key < key) {
                    current = tree[current].right;
                } else {
                    break;
                }
            }

            if (current == -1) continue;

            bool mistake = false;
            double sum = 0.0;
            double count = 0.0;

            for (int j = path.size() - 1; j >= 0; j--) {
                if (path[j] == i) {
                    mistake = true;
                }

                if (mistake) {
                    sum += tree[path[j]].key;
                    count++;
                }

                if (path[j] == current) break;
            }

            if (count > 0) {
                expectation += sum / count;
            }
        }

        cout << fixed << setprecision(10) << expectation << endl;
    }

    return 0;
}