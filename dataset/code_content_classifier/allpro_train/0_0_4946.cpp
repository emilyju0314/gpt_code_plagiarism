#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long findIndex(unsigned long long n, unsigned int k) {
    unsigned long long sum = (k*(k+1))/2;
    unsigned long long base = (n-1) / sum;

    unsigned long long residue = (n-1) % sum;
    if(residue < k) return 1 + base*k + residue;
    return 1 + base*k + (residue - k + 1)/2;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        unsigned long long n;
        unsigned int k;
        cin >> n >> k;

        unsigned long long index = findIndex(n, k);
        cout << index << endl;
    }

    return 0;
}