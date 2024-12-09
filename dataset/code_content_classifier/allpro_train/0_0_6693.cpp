#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, m, n;
    cin >> h >> m >> n;

    vector<int> table(h, -1); // Initialize hash table to empty
    vector<int> dummyCalls(n, 0); // Initialize dummy call count for each object

    int totalDummyCalls = 0;

    for (int i = 0; i < n; i++) {
        char op;
        int id, hash;
        cin >> op >> id;

        if (op == '+') {
            cin >> hash;
            int currHash = hash % h;
            while (table[currHash] != -1) {
                currHash = (currHash + m) % h;
                dummyCalls[i]++;
            }
            table[currHash] = id;
            totalDummyCalls += dummyCalls[i];
        } else {
            for (int j = 0; j < h; j++) {
                if (table[j] == id) {
                    table[j] = -1;
                    break;
                }
            }
        }
    }

    cout << totalDummyCalls << endl;

    return 0;
}