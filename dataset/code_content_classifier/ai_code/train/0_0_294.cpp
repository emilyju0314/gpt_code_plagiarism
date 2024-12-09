#include <iostream>
#include <string>

using namespace std;

bool isEquivalent(string a, string b) {
    if (a == b) {
        return true;
    }
    int n = a.length();
    string a1 = a.substr(0, n/2);
    string a2 = a.substr(n/2, n);
    string b1 = b.substr(0, n/2);
    string b2 = b.substr(n/2, n);
    
    return ((isEquivalent(a1, b1) && isEquivalent(a2, b2)) || (isEquivalent(a1, b2) && isEquivalent(a2, b1)));
}

int main() {
    string a, b;
    cin >> a >> b;
    
    if (isEquivalent(a, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}