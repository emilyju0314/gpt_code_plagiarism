#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    long long count = 0;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') % 4 == 0) {
            count++;
        }
        if (i > 0) {
            int num = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (num % 4 == 0) {
                count += i;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}