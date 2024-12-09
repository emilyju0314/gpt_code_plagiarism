#include <iostream>

using namespace std;

int main() {
    int H, A, B;
    cin >> H >> A >> B;
    
    int count = 0;
    
    for(int i = A; i <= B; i++) {
        if(H % i == 0) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}