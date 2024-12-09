#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(long long num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    sort(x.begin(), x.end());
    
    vector<long long> result;
    for (int i = 0; i < n && result.size() < k; i++) {
        if (is_prime(x[i])) {
            result.push_back(x[i]);
        }
    }
    
    if (result.size() < k) {
        cout << "0" << endl;
    } else {
        for (int i = 0; i < k; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}