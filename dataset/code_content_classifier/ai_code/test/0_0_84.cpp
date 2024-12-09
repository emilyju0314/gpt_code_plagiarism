#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long c(int l, int r) {
    long long count = 0;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            if (gcd(i, j) >= l) {
                count++;
            }
        }
    }
    return count;
}

long long f(int n, int k) {
    vector<int> sequence(k + 2);
    sequence[0] = 0;
    sequence[k + 1] = n;
    
    long long sum = 0;
    for (int i = 1; i <= k + 1; i++) {
        sum += c(sequence[i-1] + 1, sequence[i]);
        sequence[i] = (sequence[i-1] + sequence[k + 1]) / 2;
    }
    
    return sum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        cout << f(n, k) << endl;
    }
    
    return 0;
}