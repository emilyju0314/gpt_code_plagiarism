#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

string getString(ll num) {
    string str = to_string(num);
    if(str.size() <= 18){
        return str;
    }
    return str.substr(str.size() - 18);
}

bool checkSequence(int n, ll a, ll d, ll b, ll e) {
    vector<ll> sequence;
    for (int i = 0; i < n; i++) {
        sequence.push_back(a + i*d);
    }
    
    for (int i = 0; i < n; i++) {
        ll fib_num = 0;
        ll fib_one = 0;
        ll fib_two = 1;
        ll fib_i = fib_one + fib_two;
        while (fib_i < pow(10, 18)) {
            if (sequence[i] == stoll(getString(fib_i))) {
                fib_num = fib_i;
                break;
            }
            fib_i = fib_one + fib_two;
            fib_one = fib_two;
            fib_two = fib_i;
        }
        
        if (sequence[i] != stoll(getString(fib_num))) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    ll a, d;
    cin >> n >> a >> d;
    
    for (ll b = 1; b < pow(2, 64); b++) {
        for (ll e = 1; e < pow(2, 64); e++) {
            if (checkSequence(n, a, d, b, e)) {
                cout << b << " " << e << endl;
                return 0;
            }
        }
    }
    
    cout << -1 << endl;

    return 0;
}