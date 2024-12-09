#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    
    // Reverse the string
    reverse(input.begin(), input.end());
    
    cout << input << endl;
    
    return 0;
}