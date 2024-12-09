#include <iostream>
#include <vector>
#include <unordered_set>

#define MOD 998244353

using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int nA, nB;
    cin >> nA;
    vector<pair<long long, long long>> A(nA);
    
    for (int i = 0; i < nA; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    cin >> nB;
    vector<pair<long long, long long>> B(nB);
    
    for (int i = 0; i < nB; i++) {
        cin >> B[i].first >> B[i].second;
    }
    
    unordered_set<long long> ans;
    
    for (auto a : A) {
        for (auto b : B) {
            for (long long i = a.first; i <= a.second; i++) {
                for (long long j = b.first; j <= b.second; j++) {
                    ans.insert(i ^ j);
                }
            }
        }
    }
    
    long long result = 0;
    for (auto num : ans) {
        result = (result + num) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}