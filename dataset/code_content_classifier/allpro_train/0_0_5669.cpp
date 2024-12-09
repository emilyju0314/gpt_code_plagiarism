#include <iostream>
#include <string>

using namespace std;

bool checkDivisibility(string publicKey, int a, int b) {
    for (int i = 1; i < publicKey.length(); i++) {
        string left = publicKey.substr(0, i);
        string right = publicKey.substr(i);
        
        if (left[0] == '0' || right[0] == '0') {
            continue;
        }
        
        if (stoll(left) % a == 0 && stoll(right) % b == 0) {
            cout << "YES" << endl;
            cout << left << endl << right << endl;
            return true;
        }
    }
    
    return false;
}

int main() {
    string publicKey;
    int a, b;
    
    cin >> publicKey >> a >> b;
    
    if (!checkDivisibility(publicKey, a, b)) {
        cout << "NO" << endl;
    }
    
    return 0;
}