#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int a, b;
    cin >> a >> b;

    // Process the input string to count the number of opening and closing parentheses
    int openCount = 0, closeCount = 0;

    for(char c : s) {
        if(c == '(') {
            openCount++;
        } else {
            closeCount++;
        }
    }

    // Calculate the result based on the values of a and b
    int result = abs(openCount - closeCount);
    
    // Output the result
    cout << result << endl;

    return 0;
}