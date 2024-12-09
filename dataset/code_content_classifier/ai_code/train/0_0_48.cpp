#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;

    vector<int> memory(m, 0); // 0 represents free memory
    vector<int> identifiers; // to store identifiers of allocated blocks

    int next_id = 1;

    for (int i = 0; i < t; i++) {
        string operation;
        cin >> operation;

        if (operation == "alloc") {
            int n;
            cin >> n;
            int start = -1;
            for (int j = 0; j <= m - n; j++) {
                bool found = true;
                for (int k = 0; k < n; k++) {
                    if (memory[j + k] != 0) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    start = j;
                    break;
                }
            }

            if (start != -1) {
                for (int j = start; j < start + n; j++) {
                    memory[j] = next_id;
                }
                cout << next_id << endl;
                identifiers.push_back(next_id);
                next_id++;
            } else {
                cout << "NULL" << endl;
            }
        } else if (operation == "erase") {
            int x;
            cin >> x;
            bool found = false;
            for (int j = 0; j < m; j++) {
                if (memory[j] == x) {
                    memory[j] = 0;
                    found = true;
                }
            }
            if (found) {
                cout << "ERASED" << endl;
            } else {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (operation == "defragment") {
            int idx = 0;
            for (int j = 0; j < m; j++) {
                if (memory[j] != 0) {
                    memory[idx++] = memory[j];
                }
            }
            for (int j = idx; j < m; j++) {
                memory[j] = 0;
            }
        }
    }

    return 0;
}