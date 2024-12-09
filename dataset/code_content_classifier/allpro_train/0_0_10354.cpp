#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string equation;
    getline(cin, equation);

    int plus_count = 0, minus_count = 0;

    for(char c : equation) {
        if(c == '+') {
            plus_count++;
        } else if(c == '-') {
            minus_count++;
        }
    }

    int n;
    sscanf(equation.c_str(), "%*[^0123456789]%d", &n);

    int max_total = n * (plus_count + 1) - minus_count;
    int min_total = n - plus_count + minus_count;

    if(max_total <= n && n <= min_total) {
        cout << "Possible" << endl;
        
        vector<int> numbers;
        numbers.push_back(n);

        for(int i = 0; i < equation.length(); i++) {
            if(equation[i] == '?') {
                if(equation[i + 2] == '+') {
                    numbers.push_back(1);
                } else {
                    numbers.push_back(n);
                }
            }
        }

        for(int i = 0; i < numbers.size(); i++) {
            cout << numbers[i];
            if(i < numbers.size() - 1) {
                if(equation[i * 2 + 1] == '+') {
                    cout << " + ";
                } else {
                    cout << " - ";
                }
            }
        }
        cout << " = " << n << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}