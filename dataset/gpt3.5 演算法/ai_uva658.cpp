#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    bool first = true;

    while (cin >> n && n != 0) {
        if (!first) {
            cout << endl;
        }

        first = false;
        
        bool found = false;
        for (int fghij = 1234; fghij <= 98765 / n; ++fghij) {
            int abcde = fghij * n;

            int temp, used = (fghij < 10000);
            temp = abcde; 
            while (temp) { 
                used |= 1 << temp % 10; 
                temp /= 10; 
            }
            temp = fghij; 
            while (temp) { 
                used |= 1 << temp % 10; 
                temp /= 10; 
            }
            if (used == (1 << 10) - 1) {
                found = true;
                cout << abcde << " / " << (fghij < 10000 ? "0" : "") << fghij << " = " << n << endl;
            } 
        }

        if (!found) {
            cout << "There are no solutions for " << n << "." << endl;
        }
    }

    return 0;
}
