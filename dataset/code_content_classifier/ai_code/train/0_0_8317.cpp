#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<int> cnt(n/2, 0);
    int balance = 0;
    vector<char> result;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (balance < k/2) {
                result.push_back('(');
            }
            balance++;
        } else {
            if (cnt[balance-1] < 2 && balance > 0) {
                result.push_back(')');
                cnt[balance-1]++;
            }
            balance--;
        }
    }
    
    for (char c : result) {
        cout << c;
    }
    
    return 0;
}