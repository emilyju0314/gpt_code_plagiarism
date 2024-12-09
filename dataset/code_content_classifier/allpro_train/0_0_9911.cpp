#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a;
    cin >> a;
    
    sort(a.begin(), a.end());
    
    string result;
    do {
        if (a[0] != '0' && stoi(a) % 7 == 0) {
            result = a;
            break;
        }
    } while (next_permutation(a.begin(), a.end()));
    
    if (result.empty()) {
        cout << "0" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}