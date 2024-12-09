#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    string x_str;
    cin >> x_str;

    long long x = stoll(x_str);

    unordered_map<long long, int> positions;
    int n = s.size();
    long long num = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        num = num * 10 + (s[i] - '0');
        positions[num] = i;
        
        if (num % x == 0 && num / x != 0 && positions.find(num / x) != positions.end()) {
            cout << positions[num / x] + 1 << " " << i << "\n";
            cout << i + 1 << " " << i + 1 << "\n";
            return 0;
        }
    }

    num = 0;
    for (int i = 0; i < n - 1; ++i) {
        num = num * 10 + (s[i] - '0');
        
        if (num + (s[i + 1] - '0') == x && num != 0 && s[i + 1] != '0') {
            cout << i + 1 << " " << i + 1 << "\n";
            cout << i + 2 << " " << i + 2 << "\n";
            return 0;
        }
    }

    return 0;
}