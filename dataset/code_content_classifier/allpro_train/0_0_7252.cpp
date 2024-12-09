#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    long long count = 0;
    for(int a = 1; a <= N; a++) {
        for(int b = 1; b <= N; b++) {
            for(int c = 1; c <= N; c++) {
                if((a + b) % K == 0 && (b + c) % K == 0 && (c + a) % K == 0) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}