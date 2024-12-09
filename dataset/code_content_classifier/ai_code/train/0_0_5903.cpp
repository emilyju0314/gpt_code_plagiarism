#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        string result = "";

        if (n1 == 0) {
            if (n0 > 0) {
                result += string(n0+1, '0');
            } else {
                result += string(n2+1, '1');
            }
        } else {
            string ones = "";
            int x = 0;
            if (n1 % 2 == 0) {
                ones = string(n1, '1');
                if (n0 > 0) {
                    x = 1;
                    result += "0";
                }
            } else {
                ones = string(n1-1, '1');
                if (n0 > 0) {
                    x = 1;
                    result += "00";
                } else {
                    result += "1";
                }
            }
            
            string zeroes = string(n0, '0');
            string twos = string(n2, '1');
            
            result += ones + zeroes + twos;

            if (x == 1) {
                swap(result[result.size()-1], result[result.size()-2]);
            }
        }

        cout << result << endl;
    }

    return 0;
}