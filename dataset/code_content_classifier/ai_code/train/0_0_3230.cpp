#include <iostream>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    long long result = 1;
    for(int i = 1; i <= n - 2; i++) {
        result = (result * 2) % m;
    }
    
    cout << result << endl;
    
    return 0;
}