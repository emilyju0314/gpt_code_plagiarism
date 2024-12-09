#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, d1, x;
    cin >> N >> d1 >> x;
    
    double ans = 0.0;
    ans += (double)(d1 + 2*N*x)*(N-1)/2;
    
    cout << fixed << setprecision(9) << ans << endl;
    
    return 0;
}