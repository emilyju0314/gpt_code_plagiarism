#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    double min_time = 1000000; // Initialize with a large number

    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;

        double distance = sqrt(pow(a - x, 2) + pow(b - y, 2));
        double time = distance / v;
        
        if (time < min_time) {
            min_time = time;
        }
    }

    cout << fixed;
    cout.precision(15);
    cout << min_time << endl;

    return 0;
}