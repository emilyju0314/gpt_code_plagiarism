#include <iostream>
#include <string>

using namespace std;

bool isSquare(string s) {
    int n = s.length();
    if (n % 2 != 0) {
        return false;
    }
    
    string firstHalf = s.substr(0, n/2);
    string secondHalf = s.substr(n/2, n/2);
    
    if (firstHalf == secondHalf) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        if (isSquare(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}