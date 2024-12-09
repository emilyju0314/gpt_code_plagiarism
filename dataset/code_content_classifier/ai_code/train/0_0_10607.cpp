#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    
    string a;
    cin >> a;
    
    vector<int> count(10, 0); // Count the frequency of each digit in a
    
    for (int i = 0; i < n; i++) {
        count[a[i] - '0']++;
    }
    
    string x; // The resulting maximum possible integer
    
    // Start from digit 9 and go down to 2
    for (int i = 9; i >= 2; i--) {
        while (count[i] > 0) {
            x += to_string(i);
            
            // Remove the factorial of i's digits from count
            int num = i;
            for (char c : to_string(i)) {
                count[c - '0']--;
            }
        }
    }
    
    cout << x << endl;
    
    return 0;
}