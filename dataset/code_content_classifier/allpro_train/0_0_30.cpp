#include <iostream>
#include <vector>

using namespace std;

bool findLuckyNumbers(long long n, vector<long long>& luckyNumbers) {
    luckyNumbers.clear();
    if (n % 7 == 0) {
        for (int i = 0; i < n / 7; i++) {
            luckyNumbers.push_back(7);
        }
        return true;
    } else if (n % 4 == 0) {
        for (int i = 0; i < n / 4; i++) {
            luckyNumbers.push_back(4);
        }
        return true;
    } else if (n % 47 == 0) {
        for (int i = 0; i < n / 47; i++) {
            luckyNumbers.push_back(47);
        }
        return true;
    } else if (n % 74 == 0) {
        for (int i = 0; i < n / 74; i++) {
            luckyNumbers.push_back(74);
        }
        return true;
    } else if (n >= 444 && findLuckyNumbers(n-444, luckyNumbers)) {
        luckyNumbers.push_back(444);
        return true;
    } else if (n >= 7 && findLuckyNumbers(n-7, luckyNumbers)) {
        luckyNumbers.push_back(7);
        return true;
    } else if (n >= 4 && findLuckyNumbers(n-4, luckyNumbers)) {
        luckyNumbers.push_back(4);
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long ni;
        cin >> ni;

        vector<long long> luckyNumbers;
        if (findLuckyNumbers(ni, luckyNumbers)) {
            for (long long num : luckyNumbers) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}