#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count_a = 0;
    for(char c : s) {
        if(c == 'a') {
            count_a++;
        }
    }

    int half = s.length() / 2;
    int good_count = min(count_a * 2 - 1, half);
    
    cout << good_count << endl;

    return 0;
}