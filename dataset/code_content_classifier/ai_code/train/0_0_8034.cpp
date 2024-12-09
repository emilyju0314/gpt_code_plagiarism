#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_set<int> numbers;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (numbers.count(num) > 0) {
            numbers.erase(num);
        } else {
            numbers.insert(num);
        }
    }

    cout << numbers.size() << endl;

    return 0;
}