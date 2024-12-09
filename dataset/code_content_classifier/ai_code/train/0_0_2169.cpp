#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<string, int> dict;

    while (q--) {
        int op;
        string key;
        cin >> op >> key;

        if (op == 0) {
            int x;
            cin >> x;
            dict[key] = x;
        } else if (op == 1) {
            if (dict.find(key) != dict.end()) {
                cout << dict[key] << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (op == 2) {
            dict.erase(key);
        }
    }

    return 0;
}