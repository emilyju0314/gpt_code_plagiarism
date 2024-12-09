#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    bool mojtabaWins = false;
    for(int i = 0; i < n; i++) {
        if(!isPrime(numbers[i])) {
            mojtabaWins = true;
            break;
        }
    }
    
    if(mojtabaWins) {
        cout << "Mojtaba" << endl;
    } else {
        cout << "Arpa" << endl;
    }
    
    return 0;
}