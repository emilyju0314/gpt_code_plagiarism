#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, A, cf, cm;
    long long m;
    cin >> n >> A >> cf >> cm >> m;

    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    sort(skills.begin(), skills.end());

    long long force = 0;
    for (int i = 0; i < n; i++) {
        force += (skills[i] == A) ? cf : 0;
    }
    
    int min_skill = skills[0];
    long long min_force = force + min_skill * cm;

    vector<int> a_prime(n, A);
    long long remaining_cost = m;
    
    for (int i = 0; i < n; i++) {
        long long cost = 0;
        
        if (skills[i] < A) {
            cost = (A - skills[i]) * cf;
        }
        
        if (cost <= remaining_cost) {
            a_prime[i] = A;
            force += cf;
            remaining_cost -= cost;
        } else {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (a_prime[i] == A) {
            if (force - cf + cm * skills[i] > min_force) {
                a_prime[i] = skills[i];
                force = force - cf + cm * skills[i];
            }
        }
    }

    cout << force << endl;
    for (int i = 0; i < n; i++) {
        cout << a_prime[i] << " ";
    }
    cout << endl;

    return 0;
}