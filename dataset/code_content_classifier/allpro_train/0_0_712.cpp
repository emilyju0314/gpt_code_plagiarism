#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int d;
        cin >> d;

        int a = 1;
        int count = 0;

        while(count < 4) {
            a++;
            vector<int> divisors;
            for(int j = 1; j <= a; j++) {
                if(a % j == 0) {
                    divisors.push_back(j);
                }
            }

            if(divisors.size() >= 4) {
                bool valid = true;
                for(int j = 0; j < divisors.size() && valid; j++) {
                    for(int k = j+1; k < divisors.size() && valid; k++) {
                        if(abs(divisors[j] - divisors[k]) < d) {
                            valid = false;
                        }
                    }
                }

                if(valid) {
                    count = 4;
                }
            }
        }

        cout << a << endl;
    }

    return 0;
}