#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimesInRange(int p, int m, int MP) {
    int count = 0;
    for (int i = max(2, p - m); i <= min(MP, p + m); i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int totalPrize = 0;
        int lotterySales = n * 101; // selling price is 1 subprime
        for (int i = 0; i < n; i++) {
            int p, m;
            cin >> p >> m;
            int X = countPrimesInRange(p, m, 999983); // MP = 999983
            totalPrize += X;
        }
        
        int amountBilled = max(0, totalPrize - lotterySales);
        cout << amountBilled << endl;
    }
    
    return 0;
}