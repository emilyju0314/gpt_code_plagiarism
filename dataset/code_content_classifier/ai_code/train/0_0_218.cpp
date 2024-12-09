#include <iostream>
using namespace std;

int main() {
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;

    int pages_read = 0;
    int days = 0;
    int speed = v0;
    
    while(pages_read < c) {
        days++;
        pages_read += speed;
        
        if(pages_read >= c) {
            break;
        }
        
        if(speed + a <= v1) {
            speed += a;
        } else {
            speed = v1;
        }
        
        if(days > 1) {
            pages_read -= l;
        }
    }
    
    cout << days << endl;

    return 0;
}