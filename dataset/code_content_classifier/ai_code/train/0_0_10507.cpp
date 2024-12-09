#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << 5 << endl;
    
    cout << fixed << setprecision(15);
    
    for(int i = 0; i < 5; i++) {
        double x = 10 * cos(2 * M_PI * i / 5);
        double y = 10 * sin(2 * M_PI * i / 5);
        cout << x << " " << y << endl;
    }

    for(int i = 0; i < n; i++) {
        cout << "1 3 5 2 4" << endl;
    }

    for(int i = 0; i < 5 * n + 1; i++) {
        cout << i % 5 + 1 << " ";
    }
    
    cout << endl;

    return 0;
}