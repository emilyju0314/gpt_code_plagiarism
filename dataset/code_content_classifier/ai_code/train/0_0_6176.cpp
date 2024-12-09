#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int onesA = 0, onesB = 0;
    for(char c : a) {
        if(c == '1') onesA++;
    }
    for(char c : b) {
        if(c == '1') onesB++;
    }

    if(onesA % 2 == onesB % 2 && onesA <= onesB) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}