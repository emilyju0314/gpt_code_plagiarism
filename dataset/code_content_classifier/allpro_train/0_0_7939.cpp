#include <iostream>
#include <string>

using namespace std;

string findPalindrome(string A) {
    string B = A;
    
    for(int i = A.length() - 1; i >= 0; i--) {
        B += A[i]; // append the reverse of string A to B
    }
    
    return B;
}

int main() {
    string A;
    cin >> A;
    
    string B = findPalindrome(A);
    
    cout << B << endl;
    
    return 0;
}