#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void testCase() {
    ll k;
    cin >> k;
    if (k%2 == 1) {
        cout << -1 << "\n";
        return;
    }
    vector<int> steps;
    k /= 2;
    for (int i = 61; i >= 1; i--) {
        while ((1LL << i)-1 <= k) {
            k -= (1LL << i)-1;
            steps.push_back(i);
        }
    }
    int sum = 0;
    for (int x : steps) sum += x;
    cout << sum << "\n";
    for (int x : steps) {
        cout << 1 << " ";
        for (int i = 0; i < x-1; i++) cout << 0 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        testCase();
    }
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
