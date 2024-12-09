#include <iostream>
#include <map>
#include <string>

using namespace std;

int countOccurrences(string str) {
    int count = 0;
    for (size_t i = 0; i < str.length() - 3; i++) {
        if (str.substr(i, 4) == "haha") {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<string, string> variables;

        while (n--) {
            string statement;
            cin >> statement;

            if (statement.find(":=") != string::npos) {
                string var, val;
                cin >> var;
                cin >> val;
                variables[var] = val;
            } else {
                string var, a, b, op;
                cin >> var >> op >> a >> b;
                variables[var] = variables[a] + variables[b];
            }
        }

        string lastVar = (--variables.end())->first;
        int occurrences = countOccurrences(variables[lastVar]);
        cout << occurrences << endl;
    }

    return 0;
}