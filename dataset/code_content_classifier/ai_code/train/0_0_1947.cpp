#include <iostream>
#include <vector>

using namespace std;

int n, l;
vector<long long> t, x, y;

string generateProgram(int length) {
    if (length == 0) return "";

    string possibleMoves = "ULDR";
    for (char move : possibleMoves) {
        string currentProgram = string(length, move);
        string prefix = generateProgram(length - l);

        if (prefix.size() > 0) {
            currentProgram = prefix + currentProgram;
        }

        bool validProgram = true;
        long long currX = 0, currY = 0;
        for (int i = 0; i < length; i++) {
            if (currentProgram[i] == 'U') currY++;
            else if (currentProgram[i] == 'L') currX--;
            else if (currentProgram[i] == 'D') currY--;
            else if (currentProgram[i] == 'R') currX++;

            if (currX != x[i] || currY != y[i]) {
                validProgram = false;
                break;
            }
        }

        if (validProgram) return currentProgram;
    }

    return "";
}

int main() {
    cin >> n >> l;
    t.resize(n);
    x.resize(n);
    y.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    for (int length = l; length <= 2*l; length++) {
        string program = generateProgram(length);
        if (program.size() > 0) {
            cout << program << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}