#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    bool isHitachi = true;
    int len = S.length();

    if (len % 2 != 0) {
        isHitachi = false;
    } else {
        for (int i = 0; i < len; i += 2) {
            if (S.substr(i, 2) != "hi") {
                isHitachi = false;
                break;
            }
        }
    }

    if (isHitachi) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}