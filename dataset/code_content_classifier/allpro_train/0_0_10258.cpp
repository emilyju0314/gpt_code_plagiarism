#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int red_count = 0;
    long long operations = 0;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            red_count++;
        }
    }
    
    operations = red_count;
    for(int i = 0; i < red_count; i++) {
        if(s[i] == 'B') {
            operations += (n - i) - (red_count - i);
        }
    }
    
    cout << operations << endl;
    
    return 0;
}