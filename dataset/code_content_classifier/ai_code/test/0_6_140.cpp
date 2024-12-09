#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int count = 0;
        for(int i = 1; i * i * i <= n; i++){
            for(int j = 1; j * j * j <= n; j++) {
                if(i * i * i <= n && j * j * j <= n) {
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}