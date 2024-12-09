#include <iostream>
using namespace std;

int main() {
    long long D;
    cin >> D;

    int count = 0;
    for(int digits = 1; digits <= 18; digits++) {
        for(long long num = 1; num <= 9; num++) {
            long long N = num, revN = 0;

            for(int i = 0; i < digits-1; i++) {
                N *= 10;
                revN = revN*10 + num;
            }

            while(N <= 1e18) {
                if(revN == N + D) {
                    count++;
                }
                N = N*10 + num;
                revN = revN*10 + num;
            }
        }
    }

    cout << count << endl;

    return 0;
}