#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> forbiddenProducts;
    for (int i = 0; i < n; i++) {
        int product;
        cin >> product;
        forbiddenProducts.insert(product);
    }

    vector<int> sequence;
    set<int> usedNumbers;
  
    int currentNumber = 1;
    while (sequence.size() < m) {
        if (forbiddenProducts.find(currentNumber % m) == forbiddenProducts.end()
            && usedNumbers.find(currentNumber % m) == usedNumbers.end()) {
            sequence.push_back(currentNumber % m);
            usedNumbers.insert(currentNumber % m);
        }
        currentNumber++;
    }

    cout << sequence.size() << endl;
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}