#include <iostream>
using namespace std;

int countNumbers(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        bool valid = true;
        while (num > 0) {
            int digit = num % 10;
            if (digit != 0 && digit != 1) {
                valid = false;
                break;
            }
            num = num / 10;
        }
        if (valid) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    int result = countNumbers(n);
    cout << result << endl;
    
    return 0;
}