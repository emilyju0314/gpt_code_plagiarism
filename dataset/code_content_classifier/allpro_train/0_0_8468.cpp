#include <iostream>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    
    int count = 0;
    
    for(int i = 0; i <= A; i++) {
        for(int j = 0; j <= B; j++) {
            for(int k = 0; k <= C; k++) {
                if(i*500 + j*100 + k*50 == X) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}