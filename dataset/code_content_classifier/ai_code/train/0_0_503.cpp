#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool isEquivalent(string s1, string s2) {
    // Function to check if two expressions are mathematically equivalent
    // Implement your logic here
}

int main() {
    string input;
    
    while (true) {
        // Read the first expression prepared by Mr. Simpson
        getline(cin, input);
        if (input == ".") break;
        
        string expectedAnswer = input;
        
        while (true) {
            getline(cin, input);
            if (input == ".") break;
            
            // Check if the student's answer is equivalent to the expected answer
            if (isEquivalent(expectedAnswer, input)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        
        // Print a period symbol after each block
        cout << "." << endl;
    }
    
    return 0;
}