#include <iostream>
#include <vector>
using namespace std;

vector<long long> fib;

void generateFibonacciNumbers() {
    fib.push_back(1);
    fib.push_back(2);
    
    for(int i = 2; ; i++) {
        long long nextFib = fib[i-1] + fib[i-2];
        if(nextFib > 1e18) {
            break;
        }
        fib.push_back(nextFib);
    }
}

int countDecompositions(long long n) {
    int count = 0;
    int ptr = fib.size() - 1;
    
    while(n > 0) {
        while(fib[ptr] > n) {
            ptr--;
        }
        
        n -= fib[ptr];
        count++;
    }
    
    return count;
}

int main() {
    generateFibonacciNumbers();
    
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        long long n;
        cin >> n;

        cout << countDecompositions(n) << endl;
    }
    
    return 0;
}