#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n < 3) {
            cout << -1 << endl;
        } else {
            vector<int> split_days;
            int total_days = 0;

            while(n > 1) {
                total_days++;
                if(n % 2 == 1) {
                    split_days.push_back(1);
                    n--;
                } else {
                    split_days.push_back(0);
                }
                n /= 2;
            }

            cout << total_days << endl;
            for(int i = 0; i < split_days.size(); i++) {
                cout << split_days[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}