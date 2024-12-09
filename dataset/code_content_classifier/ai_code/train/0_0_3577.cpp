#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    
    int output = 1 + (a * (a+1) / 2) + (a * (a-1) / 2);
    
    cout << output << endl;
    
    return 0;
}