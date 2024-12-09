#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isLucky(int num) {
    while(num > 0) {
        int digit = num % 10;
        if(digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    while(m--) {
        string operation;
        cin >> operation;

        if(operation == "add") {
            int l, r, d;
            cin >> l >> r >> d;
            for(int i = l-1; i < r; i++) {
                numbers[i] += d;
            }
        } else if(operation == "count") {
            int l, r;
            cin >> l >> r;
            int count = 0;
            for(int i = l-1; i < r; i++) {
                if(isLucky(numbers[i])) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}