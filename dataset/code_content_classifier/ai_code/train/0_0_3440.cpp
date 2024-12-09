#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    int min_strips = (B + A - 1) / A;
    
    cout << min_strips << endl;
    
    return 0;
}