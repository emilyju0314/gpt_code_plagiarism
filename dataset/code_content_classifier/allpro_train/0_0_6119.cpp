#include <iostream>

using namespace std;

int main() {
    int L, R, d;
    cin >> L >> R >> d;
    
    int count = 0;
    for(int i = L; i <= R; i++) {
        if(i % d == 0) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}