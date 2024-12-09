#include <iostream>
#include <string>

using namespace std;

int countLuckyDigits(long long n) {
    int count = 0;
    string num = to_string(n);
    for(char c : num) {
        if(c == '4' || c == '7') {
            count++;
        }
    }
    return count;
}

int main() {
    long long a, l;
    cin >> a >> l;

    for(long long i = a; i < a + l; i++) {
        int luckyDigitsA = countLuckyDigits(i);
        int j = a;
        while(true) {
            int luckyDigitsB = countLuckyDigits(j);
            if(luckyDigitsA == luckyDigitsB) {
                cout << j << endl;
                break;
            }
            j++;
        }
    }

    return 0;
}