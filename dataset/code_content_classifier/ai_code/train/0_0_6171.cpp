#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, m, n;
    cin >> h >> m >> n;

    vector<int> table(h, -1); // Initialize hash table with -1 indicating empty slots
    long long dummy_calls = 0;

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == '+') {
            int id, hash;
            cin >> id >> hash;

            int curr_hash = hash;
            int calls = 0;

            while (table[curr_hash % h] != -1) {
                curr_hash += m;
                calls++;
            }

            table[curr_hash % h] = id; // Add object to hash table
            dummy_calls += calls;
        } else if (op == '-') {
            int id;
            cin >> id;

            for (int j = 0; j < h; j++) {
                if (table[j] == id) {
                    table[j] = -1; // Delete object from hash table
                    break;
                }
            }
        }
    }

    cout << dummy_calls << endl;

    return 0;
}