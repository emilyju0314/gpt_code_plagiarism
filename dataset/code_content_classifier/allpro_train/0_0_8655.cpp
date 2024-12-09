#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int sum = a + b + c;
    
    if (sum < 10) {
        cout << "Taro";
    } else {
        cout << "Hanako";
    }
    
    return 0;
}