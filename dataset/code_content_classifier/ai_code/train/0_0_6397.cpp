#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    
    long long time = 0;
    long long speed = 1;
    
    while (true) {
        time++;
        if (t == time) {
            break;
        }
        
        if (speed == 1) {
            speed = 3;
        } else if (speed == 3) {
            speed = 1;
        }
    }
    
    cout << time << endl;
    
    return 0;
}