#include <iostream>
using namespace std;

int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    // Calculate the result
    int result = a1 * a2;
    result += a3;
    
    cout << result << endl;
    
    return 0;
}