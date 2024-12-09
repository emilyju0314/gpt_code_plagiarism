#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    int N;
    vector<string> P;

    cin >> S >> N;

    for (int i = 0; i < N; i++) {
        string p;
        cin >> p;
        P.push_back(p);
    }

    int operations = 0;
    for (int i = 0; i < S.length(); i++) {
        for (int j = i; j < S.length(); j++) {
            string substring = S.substr(i, j - i + 1);
            for (string p : P) {
                if (substring.find(p) != string::npos) {
                    for (int k = i; k <= j; k++) {
                        S[k] = '*';
                    }
                    operations++;
                    break;
                }
            }
        }
    }

    cout << operations << endl;

    return 0;
}