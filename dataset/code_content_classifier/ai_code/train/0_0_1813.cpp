#include <iostream>

using namespace std;

int main() {
    int N;
    
    while (true) {
        cin >> N;
        
        if (N == 0) {
            break;
        }
        
        int count = 0;
        
        for (int i = 1; i <= N/2; i++) {
            int sum = 0;
            for (int j = i; j <= N; j++) {
                sum += j;
                if (sum == N) {
                    count++;
                    break;
                }
                if (sum > N) {
                    break;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}