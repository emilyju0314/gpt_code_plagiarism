#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<double> a(n), b(n), c(n), d(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        
        double max_mesh = 0.0;
        // Calculate the size of largest mesh
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                double x_diff = b[i] - a[j];
                double y_diff = d[j] - c[i];
                max_mesh = max(max_mesh, min(x_diff, y_diff));
            }
        }
        
        cout << fixed << setprecision(6) << max_mesh << endl;
    }
    
    return 0;
}