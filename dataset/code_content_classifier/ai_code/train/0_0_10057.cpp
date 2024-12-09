#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string y;
    
    cin >> n;
    cin >> y;
    
    int count = 0;
    
    for(int k = 1; k < n; k++) {
        bool valid = true;
        
        for(int i = 0; i < n; i++) {
            if(y[i] != y[(i+k)%n]) {
                valid = false;
                break;
            }
        }
        
        if(valid) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}