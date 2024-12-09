#include <iostream>
#include <vector>

using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n/i) {
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        
        vector<int> divisors = getDivisors(xi);
        int count = 0;
        for(int divisor : divisors) {
            bool dividesPrevNumbers = false;
            for(int j = max(1, xi - yi); j < xi; j++) {
                if(j % divisor == 0) {
                    dividesPrevNumbers = true;
                    break;
                }
            }
            if(!dividesPrevNumbers) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}