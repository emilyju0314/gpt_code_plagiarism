#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    
    bool containsVowels = false;
    
    for(char c : input) {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            containsVowels = true;
            break;
        }
    }
    
    if(containsVowels) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}