#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int counts[26] = {0};
    
    for(char c : s) {
        counts[c - 'a']++;
    }
    
    int count_n = counts['n' - 'a'];
    int count_i = counts['i' - 'a'];
    int count_e = counts['e' - 'a'];
    int count_t = counts['t' - 'a'];
    
    int max_nineteen = min({count_n, count_i, count_e / 3, count_t});
    
    cout << max_nineteen << endl;
    
    return 0;
}