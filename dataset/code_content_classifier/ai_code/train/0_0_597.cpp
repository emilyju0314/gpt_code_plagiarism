#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isIdempotent(string filter) {
    vector<int> transitions(128, -1);

    for (int i = 0; i < 128; i++) {
        if (filter[i] == '1') {
            for (int j = 0; j < 7; j++) {
                if (i & (1 << j)) {
                    transitions[i] &= ~(1 << j);
                } else {
                    transitions[i] |= (1 << j);
                }
            }
        }
    }

    for (int i = 0; i < 128; i++) {
        if (transitions[i] != -1 && transitions[transitions[i]] != -1 && transitions[transitions[transitions[i]]] == i) {
            return true;
        }
    }
    return false;
}

int main() {
    string filter;
    while (true) {
        getline(cin, filter);

        if (filter == "#") {
            break;
        }

        if (isIdempotent(filter)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}