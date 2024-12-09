#include <iostream>
#include <string>

using namespace std;

int countLuckyNumbers(int n, bool has7, bool has8) {
    if (n == 0) {
        return 1;
    }
    
    int count = 0;
    
    if (!has7) {
        count += countLuckyNumbers(n - 1, true, false);
    }
    if (!has8) {
        count += countLuckyNumbers(n - 1, false, true);
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    int maxOffices = countLuckyNumbers(n, false, false) * 2; // Each lucky number can start with either 7 or 8
    
    cout << maxOffices << endl;
    
    return 0;
}