#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int repaint = 0;
    for (int i = 0; i < S.length(); i++) {
        if (i % 2 == 0 && S[i] == '1') {
            repaint++;
        } else if (i % 2 == 1 && S[i] == '0') {
            repaint++;
        }
    }

    cout << min(repaint, (int)S.length() - repaint) << endl;

    return 0;
}