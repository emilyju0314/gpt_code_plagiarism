#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canBePalindrome(string S, vector<pair<int, int>> operations) {
    int n = S.length();
    vector<int> changes(n, 0);
    
    for(auto op : operations) {
        changes[op.first - 1]++;
        if(op.second < n)
            changes[op.second]--;
    }
    
    for(int i = 1; i < n; i++) {
        changes[i] += changes[i - 1];
    }
    
    for(int i = 0; i < n / 2; i++) {
        char start = S[i];
        char end = S[n - i - 1];
        int diff = abs(start - end);
        if(diff != 0 && diff != 26 && changes[i] % 2 != 0)
            return false;
    }
    
    return true;
}

int main() {
    string S;
    cin >> S;
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> operations;
    for(int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        operations.push_back({L, R});
    }
    
    if(canBePalindrome(S, operations)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}