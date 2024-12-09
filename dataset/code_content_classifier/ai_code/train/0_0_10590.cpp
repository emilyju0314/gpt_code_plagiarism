#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Initialize a string s with n characters 
    // and all characters set to the first character in the Latin alphabet
    string s(n, 'a');

    // Update the string s to minimize the cost
    for (int i = 1; i < n; i++) {
        s[i] = 'a' + i % k;
    }

    // Print the resulting string
    cout << s << endl;

    return 0;
}