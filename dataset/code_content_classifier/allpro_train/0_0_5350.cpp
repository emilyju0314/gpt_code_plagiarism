#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int count = 0;
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == '1') {
            count++;
        }
    }

    cout << min(count, (int)S.length() - count) << endl;

    return 0;
}