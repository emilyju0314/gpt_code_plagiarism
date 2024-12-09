#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int countCloseNumbers(long long n, int m) {
    string numStr = to_string(n);
    sort(numStr.begin(), numStr.end());
    
    int count = 0;
    do {
        if (numStr[0] != '0') {
            long long x = stoll(numStr);
            if (x % m == 0) {
                count++;
            }
        }
    } while (next_permutation(numStr.begin(), numStr.end()));
    
    return count;
}

int main() {
    long long n;
    int m;
    cin >> n >> m;
    
    int result = countCloseNumbers(n, m);
    
    cout << result << endl;
    
    return 0;
}