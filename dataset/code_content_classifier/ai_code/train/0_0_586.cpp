#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    
    while(cin >> a >> b >> n) {
        int s = 0;
        
        int remainder = a % b;
        
        for(int i = 0; i < n; i++) {
            s += (remainder * 10) / b;
            remainder = (remainder * 10) % b;
        }
        
        cout << s << endl;
    }
    
    return 0;
}