#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    vector<int> b(N);
    
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    
    for(int k = 0; k < N; k++) {
        int x = a[0] ^ b[(0 + k) % N];
        bool valid = true;
        
        for(int i = 0; i < N; i++) {
            if((a[i] ^ x) != b[(i + k) % N]) {
                valid = false;
                break;
            }
        }
        
        if(valid) {
            cout << k << " " << x << endl;
        }
    }
    
    return 0;
}