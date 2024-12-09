#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double calculateTime(int checkpoint, int distance, int n, vector<int>& a, double b, int r, double v, double e, double f) {
    if (checkpoint == n) {
        return 0.0;
    }
    
    double timeWithoutChange = calculateTime(checkpoint + 1, a[checkpoint + 1] - a[checkpoint], n, a, b, r, v, e, f) + 1/(v - f * (a[checkpoint] - distance));
    double timeWithChange = b + calculateTime(checkpoint + 1, a[checkpoint + 1] - a[checkpoint], n, a, b, a[checkpoint], v, e, f);
    
    return min(timeWithoutChange, timeWithChange);
}

int main() {
    while (true) {
        int n;
        cin >> n;
        
        if (n == 0) {
            break;
        }
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        double b, v, e, f;
        int r;
        cin >> b >> r >> v >> e >> f;
        
        cout << fixed << setprecision(4) << calculateTime(0, a[0], n-1, a, b, r, v, e, f) << endl;
    }
    
    return 0;
}