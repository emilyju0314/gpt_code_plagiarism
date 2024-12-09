#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<string> choices(N);
    for (int i = 0; i < N; i++) {
        cin >> choices[i];
    }

    vector<string> result;

    for (string choice : choices) {
        if (choice == "AB") {
            if (A > B) {
                A--;
                B++;
                result.push_back("B");
            } else {
                A++;
                B--;
                result.push_back("A");
            }
        } else if (choice == "AC") {
            if (A > C) {
                A--;
                C++;
                result.push_back("C");
            } else {
                A++;
                C--;
                result.push_back("A");
            }
        } else {
            if (B > C) {
                B--;
                C++;
                result.push_back("C");
            } else {
                B++;
                C--;
                result.push_back("B");
            }
        }
    }

    bool possible = true;
    if (A < 0 || B < 0 || C < 0) {
        possible = false;
    }

    if (possible) {
        cout << "Yes" << endl;
        for (string res : result) {
            cout << res << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}