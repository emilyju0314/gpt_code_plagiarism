#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int count_representations(int num) {
    vector<int> primes;
    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }

    int count = 0;
    for (int i = 0; i < primes.size(); i++) {
        int sum = 0;
        for (int j = i; j < primes.size(); j++) {
            sum += primes[j];
            if (sum == num) {
                count++;
            }
            if (sum >= num) {
                break;
            }
        }
    }

    return count;
}

int main() {
    int num;
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        cout << count_representations(num) << endl;
    }

    return 0;
}