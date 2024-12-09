#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, c;
        cin >> n >> c;

        vector<int> a(n);
        vector<int> b(n-1);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n-1; i++) {
            cin >> b[i];
        }

        long long days = 0;
        long long money = 0;
        int position = 1;

        for(int i = 0; i < n; i++) {
            if(position < n) {
                long long daysToBuyComputer = (c - money + a[position-1] - 1) / a[position-1];
                days += daysToBuyComputer;
                money += daysToBuyComputer * a[position - 1];
            }

            if(position < n && money >= b[position - 1]) {
                money -= b[position - 1];
                position++;
            } else {
                days += n - position;
                break;
            }
        }

        cout << days << endl;
    }

    return 0;
}