#include <iostream>
#include <string>

using namespace std;

int minOperations(string a, string b) {
    int n = a.length();
    int num_ops = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            continue; // no operation needed
        } else {
            if (a[0] == b[i]) {
                a[0] = '0' + '1' - a[0]; // Change the first candle's state
                num_ops++;
            } else {
                num_ops++; // Select the i-th candle
                for (int j = 0; j <= i; j++) {
                    a[j] = '0' + '1' - a[j]; // Invert all states up to the i-th candle
                }
            }
        }
    }
    
    if (a == b) {
        return num_ops;
    } else {
        return -1;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string a, b;
        cin >> a >> b;
        
        int result = minOperations(a, b);
        cout << result << "\n";
    }
    
    return 0;
}