#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;

        vector<int> a(7);
        for(int i = 0; i < 7; i++) {
            cin >> a[i];
        }

        // Find the total number of days in a week where guest classes are held
        int total_days = 0;
        for(int i = 0; i < 7; i++) {
            total_days += a[i];
        }

        // Calculate the minimum number of days required to study k days as a guest student
        int min_days = k / total_days;
        if(k % total_days != 0) {
            min_days++;
        }

        // Calculate the shortest continuous period of days needed
        int remaining_days = k % total_days;
        if(remaining_days == 0) {
            remaining_days = total_days;
        }

        int days = min_days * 7;
        int count = min_days;
        for(int i = 0; i < 7; i++) {
            if(remaining_days <= 0) {
                break;
            }

            if(a[i] == 1) {
                count--;
                if(count == 0) {
                    days += (i + 1);
                    break;
                }
            }
            remaining_days -= a[i];
        }

        cout << days << endl;
    }

    return 0;
}