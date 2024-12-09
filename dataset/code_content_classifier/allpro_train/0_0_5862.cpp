#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    int T, F;
    char C;

    for (int i = 0; i < Q; i++) {
        cin >> T;
        if (T == 1) {
            reverse(S.begin(), S.end());
        } else {
            cin >> F >> C;
            if (F == 1) {
                S = C + S;
            } else {
                S = S + C;
            }
        }
    }

    cout << S << endl;

    return 0;
}