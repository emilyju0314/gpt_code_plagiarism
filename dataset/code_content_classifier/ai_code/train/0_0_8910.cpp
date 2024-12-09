#include <iostream>
using namespace std;

void solve(int N, long long M) {
    string result;
    
    // Initialize count of ones and zeros
    int ones = 0, zeros = 0;
    
    // Iterate through each bit position
    for (int i = N - 1; i >= 0; i--) {
        long long count = 1LL << i;
        if (M > count) {
            result += '1';
            M -= count;
            ones++;
        } else {
            result += '0';
            zeros++;
        }
    }
    
    // Complete the remaining bits with zeros
    while (result.size() < N) {
        result += '0';
        zeros++;
    }
    
    cout << result << endl;
}

int main() {
    int N, M;
    
    while (true) {
        cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        solve(N, M);
    }
    
    return 0;
}