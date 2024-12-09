#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string num;
        cin >> num;

        if(n % 2 == 1) {
            int oddCount = 0;
            for(char c : num) {
                if((c - '0') % 2 == 1) {
                    oddCount++;
                }
            }

            if(oddCount % 2 == 1) {
                cout << "1" << endl;
            } else {
                cout << "2" << endl;
            }
        } else {
            int evenCount = 0;
            for(char c : num) {
                if((c - '0') % 2 == 0) {
                    evenCount++;
                }
            }

            if(evenCount % 2 == 1) {
                cout << "2" << endl;
            } else {
                cout << "1" << endl;
            }
        }
    }

    return 0;
}