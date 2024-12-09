#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        int numbers[n];
        
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        
        int max_sum = numbers[0];
        int current_sum = numbers[0];
        
        for (int i = 1; i < n; i++) {
            current_sum = max(numbers[i], current_sum + numbers[i]);
            max_sum = max(max_sum, current_sum);
        }
        
        cout << max_sum << endl;
    }
    
    return 0;
}