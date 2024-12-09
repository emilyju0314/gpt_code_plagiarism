#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, m, n;
    cin >> h >> m >> n;

    vector<int> table(h, -1); // -1 indicates empty cell
    vector<int> dummy_calls;

    int total_dummy_calls = 0;

    for (int i = 0; i < n; i++) {
        char op;
        int id, hash;
        cin >> op >> id;

        if (op == '+') {
            cin >> hash;
            int dummy = 0;
            int index = hash;
            while (table[index] != -1) {
                dummy++;
                index = (hash + m * dummy) % h;
            }
            table[index] = id;
            dummy_calls.push_back(dummy);
            total_dummy_calls += dummy;
        } else if (op == '-') {
            for (int j = 0; j < h; j++) {
                if (table[j] == id) {
                    table[j] = -1;
                    break;
                }
            }
        }
    }

    cout << total_dummy_calls << endl;

    return 0;
}