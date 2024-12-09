#include <iostream>
using namespace std;

unsigned long long int sum_digits(unsigned long long int n) {
    unsigned long long int sum = 0;
    while(n) {
        sum += (n%10);
        n /= 10;
    }
    return sum;
} 

unsigned long long int GCD(unsigned long long int a, unsigned long long int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        unsigned long long int n;
        cin >> n;
        unsigned long long int indi_sum, Gcd;
        while(n) {
            indi_sum = sum_digits(n);
            Gcd = GCD(n, indi_sum);
            if(Gcd > 1) break;
            ++n;
        }
        cout << n << endl;
    }
    return 0;
}