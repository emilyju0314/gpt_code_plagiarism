#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string t;
    
    cin >> n; // read length of the encrypted string
    cin >> t; // read the encrypted string
    
    string s;
    int index = 0;
    
    for (int i = 1; i <= n; i++) {
        s += t[index]; // add current character to the string
        index += i; // move to the next character based on the repetition
        
    }
    
    cout << s << endl; // output the decrypted string
    
    return 0;
}