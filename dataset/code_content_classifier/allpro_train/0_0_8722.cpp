#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, A, B, C, D;
    string S;

    cin >> N >> A >> B >> C >> D;
    cin >> S;

    bool possible = false;

    for (int i = A; i < C; i++) {
        if (S[i - 1] == '.' && S[i] == '.') {
            if (i == D || (i + 1 == D && S[i + 1] != '#')) {
                possible = true;
                break;
            }
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}