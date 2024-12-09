#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> blocks(n);
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    int removed_blocks = 0;
    int prev_height = 0;
    for (int i = 0; i < n; i++) {
        if (blocks[i] > m) {
            removed_blocks += blocks[i] - m;
        } else {
            removed_blocks += min(blocks[i], prev_height);
        }
        prev_height = blocks[i];
    }

    cout << removed_blocks << endl;

    return 0;
}