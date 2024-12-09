#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int x = (n / k + 1) * k;
    
    cout << x << endl;
    
    return 0;
}