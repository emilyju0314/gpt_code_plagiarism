#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

string getKthLexicographicallySmallestBAString(int n, int k, long long x, string s) {
    vector<int> asterisksPos;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            asterisksPos.push_back(i);
        }
    }
    
    long long totalPermutations = factorial(asterisksPos.size());
    
    for(int i = 0; i < totalPermutations; i++) {
        if(x <= totalPermutations / (i+1)) {
            for(int j = asterisksPos.size()-1; j >= 0; j--) {
                int num = (i / factorial(j)) % (k+1);
                s[asterisksPos[j]] = 'a' + num;
            }
            break;
        }
        x -= totalPermutations / (i+1);
    }
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            s[i] = 'a';
        }
    }
    
    return s;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        
        string s;
        cin >> s;
        
        string result = getKthLexicographicallySmallestBAString(n, k, x, s);
        cout << result << endl;
    }
    
    return 0;
}