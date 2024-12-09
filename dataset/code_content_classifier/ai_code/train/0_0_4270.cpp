#include <iostream>
#include <vector>

using namespace std;

vector<long long> getDivisors(long long n) {
    vector<long long> divisors;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main() {
    long long q;
    cin >> q;
    
    vector<long long> divisors = getDivisors(q);
    
    if (divisors.empty()) {
        cout << "1" << endl;
        cout << "0" << endl;
    } else if (divisors.size() == 1) {
        cout << "2" << endl;
    } else {
        if (divisors.size() % 2 == 0) {
            cout << "2" << endl;
        } else {
            cout << "1" << endl;
            cout << divisors[0] << endl;
        }
    }
    
    return 0;
}