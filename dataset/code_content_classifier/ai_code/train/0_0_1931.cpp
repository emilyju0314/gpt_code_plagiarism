#include <iostream>
#include <string>

using namespace std;

bool isUnstable(char a, char b) {
    return (a == '0' && b == '1') || (a == '1' && b == '0');
}

int countBeautifulSubstrings(string s) {
    int n = s.length();
    int ans = 0;
    int consecutiveZeros = 0, consecutiveOnes = 0, consecutiveQs = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            consecutiveZeros++;
            consecutiveOnes = 0;
            consecutiveQs = 0;
        } else if (s[i] == '1') {
            consecutiveOnes++;
            consecutiveZeros = 0;
            consecutiveQs = 0;
        } else {
            consecutiveQs++;
            consecutiveZeros++;
            consecutiveOnes++;
        }
        
        ans += max(consecutiveZeros, consecutiveOnes) +  min(consecutiveZeros, consecutiveOnes) + consecutiveQs;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        
        cout << countBeautifulSubstrings(s) << endl;
    }

    return 0;
}