#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int Y, M, D;
        cin >> Y >> M >> D;

        int days = 0;

        // Calculate number of days from birthdate to millennium day
        for (int year = Y; year < 1000; year++) {
            int num_months = (year % 3 == 0) ? 10 : 10 + (year % 2);
            for (int month = 1; month <= num_months; month++) {
                if (year == 999 && month == 10 && (D == 20)) {
                    days++;
                    break;
                }
                int num_days = (month % 2 == 0) ? 19 : 20;
                if (year == Y && month == M) {
                    days += num_days - D + 1;
                } else {
                    days += num_days;
                }
            }
        }

        cout << days << endl;
    }

    return 0;
}