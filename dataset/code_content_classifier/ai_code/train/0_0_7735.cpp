#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<unordered_map<char, int>> tree1, tree2;
    tree1.push_back({});
    tree2.push_back({});

    int good_combinations = 0;

    for (int i = 0; i < n; i++) {
        int t, v;
        char c;
        cin >> t >> v >> c;

        if (t == 1) {
            tree1.push_back({});
            tree1[v][c] = tree1.size() - 1;

            for (int j = 1; j < tree2.size(); j++) {
                int m = tree2[j].size();
                if (tree2[j].find(c) != tree2[j].end()) {
                    good_combinations += m;
                }
            }
        } else {
            tree2.push_back({});
            tree2[v][c] = tree2.size() - 1;

            for (int j = 1; j < tree1.size(); j++) {
                int m = tree1[j].size();
                if (tree1[j].find(c) != tree1[j].end()) {
                    good_combinations += m;
                }
            }
        }

        cout << good_combinations << endl;
    }

    return 0;
}