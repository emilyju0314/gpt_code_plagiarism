#include <iostream>
#include <cmath>

using namespace std;

int minNum2050(int n) {
    if (n % 2050 != 0) {
        return -1;
    }
    
    int count = 0;
    n /= 2050;
    
    while (n > 0) {
        count += n % 10;
        n /= 10;
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        cout << minNum2050(n) << endl;
    }
    
    return 0;
}