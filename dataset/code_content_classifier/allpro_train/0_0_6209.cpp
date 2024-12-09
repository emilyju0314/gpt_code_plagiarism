#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int remaining_water = max(0, B + C - A);
    
    cout << remaining_water << endl;
    
    return 0;
}