#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool distribute_foxes(int n, vector<int>& ages) {
    sort(ages.begin(), ages.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!is_prime(ages[i] + ages[j])) {
                return false;
            }
        }
    }
    
    int tables = n / 2;
    cout << tables << endl;
    for (int i = 0; i < tables; i++) {
        cout << "4 ";
        cout << ages[i] << " " << ages[i+tables] << " " << ages[i+1] << " " << ages[i+tables-1] << endl;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> ages(n);
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }
    
    if (distribute_foxes(n, ages)) {
        return 0;
    } else {
        cout << "Impossible" << endl;
        return 0;
    }
}