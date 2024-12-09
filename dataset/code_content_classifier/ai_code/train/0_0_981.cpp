#include <iostream>
using namespace std;

int main() {
    int a1, a2;
    cin >> a1 >> a2;
    
    cout << a1 + (a2 % 10) * 10 << endl;
    
    return 0;
}