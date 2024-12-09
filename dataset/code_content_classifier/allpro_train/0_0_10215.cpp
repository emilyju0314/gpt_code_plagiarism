#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

bool is_inconsistent(unordered_map<string, int>& unit_exponents) {
    for(auto&& entry : unit_exponents) {
        string unit = entry.first;
        int exponent = entry.second;
        if(unit_exponents.find(unit) != unit_exponents.end() && unit_exponents[unit] != exponent) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    while(cin >> N && N != 0) {
        unordered_map<string, int> unit_exponents;
        bool inconsistent = false;

        for(int i = 0; i < N; ++i) {
            string unit1, unit2, eq, pow;
            cin >> unit1 >> eq >> pow >> unit2;
            int power = stoi(pow.substr(3));

            unit_exponents[unit1] = power;
            unit_exponents[unit2] = -power;

            if(is_inconsistent(unit_exponents)) {
                inconsistent = true;
            }
        }

        if(inconsistent) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}