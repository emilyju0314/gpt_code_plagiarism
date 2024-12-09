#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        double x_a, y_a, r_a, x_b, y_b, r_b;
        cin >> x_a >> y_a >> r_a >> x_b >> y_b >> r_b;
        
        double distance_centers = sqrt(pow(x_b - x_a, 2) + pow(y_b - y_a, 2));
        
        if(distance_centers + r_b < r_a) {
            cout << "2" << endl;
        } else if(distance_centers + r_a < r_b) {
            cout << "-2" << endl;
        } else if(distance_centers < r_a + r_b) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}