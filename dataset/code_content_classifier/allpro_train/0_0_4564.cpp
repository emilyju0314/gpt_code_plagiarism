#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M;
    cin >> M;
    
    long long total_digits = 0;
    long long max_rounds = 0;
    
    for (int i = 0; i < M; i++) {
        int d, c;
        cin >> d >> c;
        total_digits += c;
        max_rounds += c - 1; // Each round eliminates 1 contestant
        
        // Check if the digit is 9
        if (d == 9) {
            max_rounds += 1;
        }
    }
    
    // Calculate the maximum rounds
    if (total_digits < 9) {
        // If total_digits is less than 9, then the number of rounds is the total number of digits
        cout << total_digits << endl;
    } else {
        cout << max_rounds << endl;
    }
    
    return 0;
}