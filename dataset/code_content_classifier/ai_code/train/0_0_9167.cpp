#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool isStronger(unordered_map<string, int>& strength, string a, string b) {
    if (strength[a] > strength[b]) {
        return true;
    }
    return false;
}

bool canInfer(vector<string>& crossings, unordered_map<string, int>& strength, string X, string Y) {
    if (find(crossings.begin(), crossings.end(), X + "-" + Y) != crossings.end()) {
        return true;
    }

    if (isStronger(strength, X, Y)) {
        return true;
    }

    return false;
}

int main() {
    int N, M;
    while (cin >> N && N != 0) {
        vector<string> crossings;
        unordered_map<string, int> strength;
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            crossings.push_back(input);
        }

        sort(crossings.begin(), crossings.end());

        for (int i = 0; i < N; i++) {
            strength[crossings[i].substr(0, crossings[i].find("-"))] = i;
            strength[crossings[i].substr(crossings[i].find("-")+1)] = i;
        }

        cout << N << endl;

        cin >> M;
        for (int i = 0; i < M; i++) {
            string question;
            cin >> question;
            string X = question.substr(0, question.find("-"));
            string Y = question.substr(question.find("-")+1);

            if (canInfer(crossings, strength, X, Y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}