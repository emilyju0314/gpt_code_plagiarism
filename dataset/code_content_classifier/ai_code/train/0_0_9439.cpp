#include <iostream>
#include <string>

using namespace std;

bool isMikomiString(string str) {
    int n = str.length();
    
    for (int lenA = 1; lenA <= n / 4; lenA++) {
        if (n % (2 * lenA) != 0) continue;
        
        string A = str.substr(0, lenA);
        string B = str.substr(lenA, lenA);
        
        string reconstructed = "";
        
        for (int i = 0; i < n / (2 * lenA); i++) {
            reconstructed += A + B + A;
        }
        
        if (reconstructed == str) {
            cout << "Love " << A << "!" << endl;
            return true;
        }
    }
    
    cout << "mitomerarenaiWA" << endl;
    return false;
}

int main() {
    string str;
    cin >> str;
    
    isMikomiString(str);
    
    return 0;
}