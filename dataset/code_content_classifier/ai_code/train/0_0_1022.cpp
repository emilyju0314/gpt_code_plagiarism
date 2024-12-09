#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int result = 0;
    for (int i = 0; i < 4; i++) {
        if (S[i] == '+') {
            result++;
        } else {
            result--;
        }
    }

    cout << result << endl;

    return 0;
}