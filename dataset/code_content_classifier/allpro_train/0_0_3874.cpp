#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N;
    cin >> N;

    int count = 0;
    
    for(int i = 2; i <= N; i++) {
        long long temp = N;
        while(temp >= i) {
            if(temp % i == 0) {
                temp /= i;
            } else {
                temp -= i;
            }
        }
        if(temp == 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}