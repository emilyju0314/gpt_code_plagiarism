#include <iostream>
#include <string>

using namespace std;

int main() {
    long long p, d;
    cin >> p >> d;

    string price = to_string(p);
    int n = price.size();

    int max_nines = 0;
    string result = price;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            string new_price = price;
            if (j <= i) {
                int diff = min(d, (long long)pow(10, j) - 1 - stoi(new_price.substr(n - j, j)));
                new_price.replace(n - j, j, to_string(stoi(new_price.substr(n - j, j)) + diff));
                for (int k = n - j - 1; k >= 0; k--) {
                    if (new_price[k] == '0') {
                        new_price[k] = '9';
                    } else {
                        break;
                    }
                }
            } else {
                int diff = min(d, (long long)pow(10, i) - 1 - stoi(new_price.substr(n - i, i)));
                new_price.replace(n - i, i, to_string(stoi(new_price.substr(n - i, i)) + diff));
                for (int k = n - i - 1; k >= 0; k--) {
                    if (new_price[k] == '0') {
                        new_price[k] = '9';
                    } else {
                        break;
                    }
                }
            }

            if (stoll(price) - stoll(new_price) <= d) {
                int count = 0;
                for (char c : new_price) {
                    if (c == '9') {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count > max_nines || (count == max_nines && new_price < result)) {
                    max_nines = count;
                    result = new_price;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}