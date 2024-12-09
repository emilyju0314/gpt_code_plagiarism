#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << endl;
        }
        else if(a > b) {
            cout << -1 << endl;
        }
        else {
            int count = 0;
            while (a < b) {
                if (b % 2 == 0 && b / 2 >= a) {
                    b /= 2;
                    count++;
                } 
                else if (b % 4 == 0 && b / 4 >= a) {
                    b /= 4;
                    count++;
                }
                else if (b % 8 == 0 && b / 8 >= a) {
                    b /= 8;
                    count++;
                }
                else {
                    break;
                }
            }

            if (a == b) {
                cout << count << endl;
            } 
            else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}