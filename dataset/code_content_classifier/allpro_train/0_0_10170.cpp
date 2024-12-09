#include <iostream>
#include <string>

using namespace std;

int main() {
    int p, x;
    cin >> p >> x;
    
    for(int i = 1; i <= 9; i++) {
        string num = to_string(i);
        while(num.length() < p) {
            string last_digit = num.substr(num.length()-1);
            num = last_digit + num.substr(0, num.length()-1);
            int num_int = stoi(num);
            if(num_int % x == 0 && num_int / x == i && num.length() == p) {
                cout << num << endl;
                return 0;
            }
        }
    }
    
    cout << "Impossible" << endl;
    
    return 0;
}