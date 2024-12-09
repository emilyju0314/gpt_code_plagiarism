#include <iostream>
#include <string>

using namespace std;

int count_matching_pairs(string s) {
    int open = 0, star = 0, pairs = 0;

    for(char c : s) {
        if(c == '(') {
            open++;
        } else if(c == ')') {
            if(open > 0) {
                open--;
                pairs++;
            }
        } else if(c == '*') {
            star = open;
        }
    }

    return pairs - star;
}

int main() {
    string s;
    cin >> s;

    cout << count_matching_pairs(s) << endl;

    return 0;
}