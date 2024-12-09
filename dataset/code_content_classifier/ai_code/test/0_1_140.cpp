#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long n;
        cin >> n;
        
        long long count = 0;
        
        int i = 1;
        while(i*i <= n) {
            count++;
            i++;
        }
        
        i = 1;
        while(i*i*i <= n) {
            count++;
            i++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}