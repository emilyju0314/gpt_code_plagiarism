#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateFactorials(int n) {
    vector<int> factorials(n+1, 0);
    factorials[0] = 1;
    factorials[1] = 1;
    for(int i = 2; i <= n; i++) {
        factorials[i] = factorials[i-1] * i;
    }
    return factorials;
}

int main() {
    int t;
    cin >> t;
    
    vector<int> factorials = calculateFactorials(5000000);
    
    for(int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        
        int count = 0;
        int n = factorials[a] / factorials[b];
        
        for(int x = 2; x*x <= n; x++) {
            while(n % x == 0) {
                n /= x;
                count++;
            }
        }
        
        if(n > 1) {
            count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}