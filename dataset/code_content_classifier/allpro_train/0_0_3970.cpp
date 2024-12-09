#include <iostream>
#include <string>
using namespace std;

bool isSymmetric(string str) {
    int n = str.length();
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    int count = 0;
    
    for (int i = 0; i < 50; i++) {
        getline(cin, input);
        
        if (isSymmetric(input)) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}