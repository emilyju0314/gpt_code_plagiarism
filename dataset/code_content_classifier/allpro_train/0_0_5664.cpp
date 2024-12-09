#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a;
    cin >> a;
    
    sort(a.begin(), a.end());

    do {
        int num = stoi(a);
        if(num % 7 == 0) {
            cout << a << endl;
            return 0;
        }
    } while(next_permutation(a.begin(), a.end()));

    cout << "0" << endl;
    
    return 0;
}