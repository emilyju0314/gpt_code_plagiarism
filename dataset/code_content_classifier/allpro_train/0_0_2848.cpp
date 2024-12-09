#include <iostream>
#include <vector>
using namespace std;

int sum_of_digits(int num, int base) {
    int sum = 0;
    while (num > 0) {
        sum += num % base;
        num /= base;
    }
    return sum;
}

int main() {
    int N, m, l;
    int case_num = 1;
    
    while (true) {
        cin >> N >> m >> l;
        if (N == 0 && m == 0 && l == 0) {
            break;
        }
        
        int ans = 1;
        while (true) {
            int sum = sum_of_digits(ans, l);
            if (sum <= l - 1) {
                int k = 1;
                int long_sum = sum;
                while (long_sum <= l - 1) {
                    long_sum = sum_of_digits(long_sum, l);
                    k++;
                }
                if (k == N) {
                    cout << "Case " << case_num << ": " << ans % m << endl;
                    break;
                }
            }
            ans++;
        }
        
        case_num++;
    }
    
    return 0;
}