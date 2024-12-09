#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    string x_str;
    cin >> x_str;

    long long x = stoll(x_str); // Convert x to long long

    for (int i = 1; i < s.size(); i++) {
        string num1 = s.substr(0, i);
        string num2 = s.substr(i);

        if (num1[0] == '0' || num2[0] == '0') continue; // Skip if any number starts with 0

        long long sum = stoll(num1) + stoll(num2);
        if (sum == x) {
            cout << "1 " << i << endl; // Print the positions of the first number
            cout << i + 1 << " " << s.size() << endl; // Print the positions of the second number
            break;
        }
    }

    return 0;
}