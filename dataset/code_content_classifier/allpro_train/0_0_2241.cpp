#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, y;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> y;

        int max_bank = 0;
        double max_interest = 0;

        for (int i = 0; i < n; i++) {
            int bank_number, annual_interest_rate, interest_type;
            cin >> bank_number >> annual_interest_rate >> interest_type;

            double principal = 1000;
            double interest = 0;
            if (interest_type == 1) {
                interest = principal * annual_interest_rate * y;
            } else if (interest_type == 2) {
                interest = principal * pow(1 + (double)annual_interest_rate / 100, y) - principal;
            }

            if (principal + interest > max_interest) {
                max_interest = principal + interest;
                max_bank = bank_number;
            }
        }

        cout << max_bank << endl;
    }

    return 0;
}