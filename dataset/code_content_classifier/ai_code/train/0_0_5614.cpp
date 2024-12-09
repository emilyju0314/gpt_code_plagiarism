#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int sum = A + B + C;
    int D = sum - A - C;
    int E = sum - B - D;
    int F = sum - C - E;
    
    cout << A << " " << B << " " << C << "\n";
    cout << D << " " << E << " " << F << "\n";
    cout << sum - D - F << " " << sum - E - A << " " << sum - B - C << "\n";
    
    return 0;
}