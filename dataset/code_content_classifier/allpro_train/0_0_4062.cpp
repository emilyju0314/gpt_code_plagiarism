#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> passwords(N);
    vector<string> evenCandidates(8);

    for (int i = 0; i < N; i++) {
        cin >> passwords[i];

        int evenIndex = 0;
        for (int j = 0; j < 5; j++) {
            if (passwords[i][j] == '0' || passwords[i][j] == '2' || passwords[i][j] == '4' || passwords[i][j] == '6'
                || passwords[i][j] == '8' || passwords[i][j] == 'a' || passwords[i][j] == 'c' || passwords[i][j] == 'e') {
                evenCandidates[evenIndex++] += passwords[i][j];
            }
        }
    }

    int maxCount = 0;
    string maxInput;

    for (int i = 0; i < N; i++) {
        int count = 0;
        string input;

        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }

            bool match = true;
            for (int k = 0; k < 5; k++) {
                if (evenCandidates[i].find(passwords[j][k]) == string::npos) {
                    match = false;
                    break;
                }
            }

            if (match) {
                count++;
                input = passwords[j];
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxInput = input;
        }
    }

    cout << maxCount << endl;
    cout << maxInput << endl;

    sort(evenCandidates.begin(), evenCandidates.end());

    for (int i = 0; i < N; i++) {
        if (evenCandidates[i] == evenCandidates[0]) {
            cout << passwords[i] << endl;
        }
    }

    return 0;
}