#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    double max_time = -1.0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        double time = -1.0;
        if (a > p) {
            time = (double)b / (a - p);
        }
        
        if (time >= 0 && (max_time == -1.0 || time < max_time)) {
            max_time = time;
        }
    }

    cout << fixed;
    cout.precision(10);

    cout << max_time << endl;

    return 0;
}