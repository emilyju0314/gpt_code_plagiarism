#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    double x, y;
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        sum += x*y;
    }
    
    cout << fixed << setprecision(3) << sum << endl;

    return 0;
}