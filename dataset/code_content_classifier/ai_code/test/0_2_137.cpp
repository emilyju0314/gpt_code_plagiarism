#include <iostream>
#include <vector>

using namespace std;

long long reverseBits(long long num) {
    vector<int> bits;
    while (num > 0) {
        bits.push_back(num % 2);
        num /= 2;
    }
    
    long long reversed = 0;
    for (int bit : bits) {
        reversed = reversed * 2 + bit;
    }
    
    return reversed;
}

int main() {
    long long x, y;
    cin >> x >> y;
    
    while (x <= y) {
        if (x == y) {
            cout << "YES" << endl;
            return 0;
        }
        
        if (y % 2 == 0) {
            y /= 2;
        } else {
            y = (y + 1) / 2;
        }
    }
    
    cout << "NO" << endl;

    return 0;
}