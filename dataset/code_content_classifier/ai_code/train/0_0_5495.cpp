#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> res(n);
    
    int i = 1;
    while (!isPrime(i)) {
        i++;
    }
    
    for (int j = 0; j < n; j++) {
        res[j] = (j + i) % n + 1;
    }
    
    for (int j = 0; j < n; j++) {
        cout << res[j] << " ";
    }
    
    return 0;
}