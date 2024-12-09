#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> stmt(N);
    for (int i = 0; i < N; i++) {
        cin >> stmt[i];
    }

    map<char, int> variables;
    int currentLine = 0;
    bool stop = false;

    while (currentLine < N) {
        string line = stmt[currentLine];
        int spacePos = line.find(' ');
        int lineNum = stoi(line.substr(0, spacePos));
        line = line.substr(spacePos + 1);

        if (variables.size() >= 5 || variables.count('a') + variables.count('b') + variables.count('c') + variables.count('d') + variables.count('s') > 1) {
            cout << "inf" << endl;
            return 0;
        }

        if (line == "HALT") {
            stop = true;
            break;
        }

        char var1 = line[4];
        char var2 = line[6];
        char var3 = line[8];
        int con = stoi(line.substr(10));

        if (line[2] == 'D') {
            if (variables[var2] + variables[var3] < 16) {
                variables[var1] = variables[var2] + variables[var3];
            } else {
                variables[var1] = 0;
            }
        } else if (line[2] == 'B') {
            if (variables[var2] - variables[var3] >= 0) {
                variables[var1] = variables[var2] - variables[var3];
            } else {
                variables[var1] = 0;
            }
        } else if (line[2] == 'T') {
            if (var2 == 'c' && var3 == '0') {
                currentLine = con;
                continue;
            } else {
                if (variables[var2] != 0) {
                    currentLine = con;
                    continue;
                }
            }
        } else if (line[2] == 'T') {
            cout << "inf" << endl;
            return 0;
        }

        currentLine++;
    }

    if (stop) {
        for (auto const& pair : variables) {
            cout << pair.first << "=" << pair.second << endl;
        }
    } else {
        cout << "inf" << endl;
    }

    return 0;
}