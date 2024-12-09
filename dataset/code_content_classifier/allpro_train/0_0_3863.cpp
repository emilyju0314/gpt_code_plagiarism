#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> forbiddenProducts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        forbiddenProducts.insert(x);
    }

    vector<int> sequence;
    for (int i = 0; i < m; i++) {
        if (forbiddenProducts.find(i) == forbiddenProducts.end()) {
            sequence.push_back(i);
        }
    }

    cout << sequence.size() << endl;
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}