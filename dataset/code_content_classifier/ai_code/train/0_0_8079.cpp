#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> answers(n);
    vector<int> truthCount(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> answers[i];

        int ai = stoi(answers[i].substr(1));
        if (answers[i][0] == '+') {
            truthCount[ai - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (answers[i][0] == '+') {
            if (truthCount[stoi(answers[i].substr(1)) - 1] == m) {
                cout << "Truth" << endl;
            } else {
                cout << "Lie" << endl;
            }
        } else {
            if (truthCount[stoi(answers[i].substr(1)) - 1] > 0) {
                cout << "Not defined" << endl;
            } else {
                cout << "Lie" << endl;
            }
        }
    }

    return 0;
}