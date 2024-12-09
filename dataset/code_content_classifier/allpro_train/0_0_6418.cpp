#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> initial(n);
    vector<string> desired(n);

    for (int i = 0; i < n; i++) {
        cin >> initial[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> desired[i];
    }

    string magical_bar;
    cin >> magical_bar;

    bool possible = true;
    vector<string> instructions;

    // Check if it is possible to transform square board into the desired pattern
    for (int i = 0; i < n; i++) {
        if (initial[0][i] != desired[0][i]) {
            instructions.push_back("row 0");
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (initial[i][0] != desired[i][0]) {
            instructions.push_back("col 0");
            break;
        }
    }

    if (instructions.empty()) {
        possible = false;
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        cout << instructions.size() << endl;
        for (int i = 0; i < instructions.size(); i++) {
            cout << instructions[i] << endl;
        }
    }

    return 0;
}