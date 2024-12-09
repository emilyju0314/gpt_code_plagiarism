#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    
    int count = 0;
    
    for(int x = 0; x <= a/2; x++) {
        int y = a - x;
        if(y >= 0 && x >= 0) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}