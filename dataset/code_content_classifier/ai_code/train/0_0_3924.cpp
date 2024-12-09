#include <iostream>

using namespace std;

int main() {
    int a, n;
    cin >> a >> n;
    
    long long p = 0;
    for (int i = 0; i < n; i++) {
        p += (long long)(a + i) * (a + i);
    }
    
    cout << p << endl;
    
    return 0;
}