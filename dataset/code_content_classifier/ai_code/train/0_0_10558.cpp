#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<int> blocks(n);
        for (int i = 0; i < n; i++) {
            cin >> blocks[i];
        }

        int removed = 0;
        while (true) {
            bool found = false;
            for (int i = 0; i < blocks.size() - 1; i++) {
                if (abs(blocks[i] - blocks[i + 1]) <= 1) {
                    blocks.erase(blocks.begin() + i, blocks.begin() + i + 2);
                    removed += 2;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }

        cout << removed << endl;
    }

    return 0;
}