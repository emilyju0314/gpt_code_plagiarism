#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

pair<int, int> find_parameters(int n, int m, string w1, string w2) {
    int p = m;
    while (!is_prime(p)) {
        p++;
    }
    
    // Find r such that H_p(w1) = H_p(w2)
    int r = 2;
    
    long long hash1 = 0, hash2 = 0;
    for (int i = 0; i < n; i++) {
        hash1 = (hash1 + (w1[i] - 'a') * pow(r, i)) % p;
        hash2 = (hash2 + (w2[i] - 'a') * pow(r, i)) % p;
    }
    
    if (hash1 == hash2) {
        return make_pair(p, r);
    }
    
    return make_pair(-1, -1); // Cannot find parameters
}

int main() {
    int n, m;
    cin >> n >> m;
    
    string w1, w2;
    cin >> w1 >> w2;
    
    pair<int, int> parameters = find_parameters(n, m, w1, w2);
    if (parameters.first != -1) {
        cout << parameters.first << " " << parameters.second << endl;
    }
    
    return 0;
}