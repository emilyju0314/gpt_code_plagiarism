#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long count = 0;
    int digits = 1;
    
    while(n > 0) {
        int current = min(n, 9);
        count += (long long)current * digits;
        n -= current;
        digits++;
    }
    
    cout << count << endl;
    
    return 0;
}