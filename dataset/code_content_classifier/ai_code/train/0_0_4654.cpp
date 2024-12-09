#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int max_coins = max(A, B) + max(max(A-1, B), max(A, B-1));
    cout << max_coins << endl;
    
    return 0;
}