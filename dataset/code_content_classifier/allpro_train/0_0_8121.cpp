#include <iostream>
#include <string>

using namespace std;

int main() {
    string N;
    cin >> N;

    bool isGood = false;
    for(int i = 0; i < 2; i++) {
        if(N[i] == N[i+1] && N[i] == N[i+2]) {
            isGood = true;
            break;
        }
    }

    if(isGood) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}