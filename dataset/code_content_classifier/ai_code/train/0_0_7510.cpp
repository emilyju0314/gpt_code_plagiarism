#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int count = 0;
    for (int i = 0; i < S.length() - 1; i++) {
        if (S[i] == 'B' && S[i+1] == 'W') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}