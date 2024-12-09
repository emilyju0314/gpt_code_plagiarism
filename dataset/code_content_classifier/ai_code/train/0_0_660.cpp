#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    double total_ways = 0;
    double winning_ways = 0;
    
    for (int k = 0; k < n; k++) {
        int count_first_two = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == s[(i + k) % n] && s[(i + 1) % n] == s[(i + 1 + k) % n]) {
                count_first_two++;
            }
        }
        
        if (count_first_two == 1) {
            winning_ways++;
        }
        
        total_ways++;
    }
    
    double probability = winning_ways / total_ways;
    cout << fixed;
    cout.precision(15);
    cout << probability << endl;
    
    return 0;
}