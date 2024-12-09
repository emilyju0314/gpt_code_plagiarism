#include <iostream>
using namespace std;

int main() {
    int m, f, b;
    cin >> m >> f >> b;
    
    int min_amount = max(0, b - m - f);
    
    if (min_amount > f) {
        cout << "NA" << endl;
    } else {
        cout << min_amount << endl;
    }
    
    return 0;
} 

// Input: 1000 3000 3000
// Output: 2000

// Input: 5000 3000 4500
// Output: 0

// Input: 500 1000 2000
// Output: NA