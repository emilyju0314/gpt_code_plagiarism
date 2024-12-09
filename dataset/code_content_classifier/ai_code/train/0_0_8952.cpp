#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> digits;
    
    // Extract digits of the number
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    
    // Print the beads for each digit
    for (int i = digits.size() - 1; i >= 0; i--) {
        int value = digits[i];
        
        // Print the go-dama
        cout << "O-|";
        
        // Print the ichi-damas shifted to the left
        for (int j = 0; j < value; j++) {
            cout << "O";
        }
        
        // Print the ichi-damas shifted to the right
        for (int j = 0; j < 4 - value; j++) {
            cout << "-";
        }
        
        cout << endl;
        
    }
    
    return 0;
}