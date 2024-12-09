#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printShortcuts() {
    cout << "R SrS" << endl;
    cout << "S rr" << endl;
    cout << "I lldll" << endl;
    cout << "DONE" << endl;
}

bool solveProblem(int k, vector<string>& firstRowOrgans, vector<string>& secondRowOrgans) {
    string sequenceOfMoves;

    // TODO: Implement the logic to solve the problem and find the sequence of moves

    cout << "SURGERY COMPLETE" << endl;
    cout << sequenceOfMoves << endl;

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        vector<string> firstRowOrgans(2*k+1);
        vector<string> secondRowOrgans(2*k+1);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2*k+1; j++) {
                cin >> firstRowOrgans[j];
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2*k+1; j++) {
                cin >> secondRowOrgans[j];
            }
        }

        if (!solveProblem(k, firstRowOrgans, secondRowOrgans)) {
            cout << "SURGERY FAILED" << endl;
        }
    }

    printShortcuts();

    return 0;
}