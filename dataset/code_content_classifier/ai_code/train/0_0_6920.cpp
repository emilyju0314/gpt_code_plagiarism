#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double d;
    cin >> d;

    double answer = sqrt(2) * d;
    
    cout << fixed << setprecision(12) << answer << endl;

    return 0;
}