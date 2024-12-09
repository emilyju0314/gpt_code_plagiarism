#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            set<int> digits;
            int hour = i, minute = j;
            while(hour > 0) {
                digits.insert(hour % 7);
                hour /= 7;
            }
            while(minute > 0) {
                digits.insert(minute % 7);
                minute /= 7;
            }
            if(digits.size() == (n + m)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}