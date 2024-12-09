#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<char, string>> rules;
set<string> validNames;

void generateValidNames(string currentName) {
    if (currentName.length() == 0) {
        validNames.insert("");
        return;
    }

    for (int i = 0; i < currentName.length(); i++) {
        for (auto rule : rules) {
            if (currentName[i] == rule.first) {
                string newName = currentName;
                newName.replace(i, 1, rule.second);
                generateValidNames(newName);
            }
        }
    }
}

int main() {
    int n, l;
    while (true) {
        cin >> n >> l;
        if (n == 0 && l == 0) {
            break;
        }

        rules.clear();
        validNames.clear();

        for (int i = 0; i < n; i++) {
            char lhs;
            string arrow, rhs;
            cin >> lhs >> arrow >> rhs;
            rules.push_back(make_pair(lhs, rhs));
        }

        string start = "S";
        generateValidNames(start);

        bool found = false;
        for (string name : validNames) {
            if (name.length() == l) {
                cout << name << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "-" << endl;
        }
    }

    return 0;
}