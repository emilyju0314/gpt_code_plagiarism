#include <iostream>
#include <set>

using namespace std;

int f(int x) {
    while (x % 10 == 0) {
        x /= 10;
    }
    return x;
}

int main() {
    int n;
    cin >> n;

    set<int> reachable_numbers;
    reachable_numbers.insert(n);

    int current_number = n;
    while (true) {
        int next_number = f(current_number + 1);
        if (reachable_numbers.find(next_number) == reachable_numbers.end()) {
            reachable_numbers.insert(next_number);
            current_number = next_number;
        } else {
            break;
        }
    }

    cout << reachable_numbers.size() << endl;

    return 0;
}