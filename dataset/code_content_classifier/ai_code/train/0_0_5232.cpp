#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int k;
    cin >> a >> k;

    for(int i = 0; i < a.size() && k > 0; i++) {
        int max_digit = i;
        for(int j = i + 1; j < a.size() && j - i <= k; j++) {
            if(a[j] > a[max_digit]) {
                max_digit = j;
            }
        }
        if(max_digit != i) {
            for(int j = max_digit; j > i; j--) {
                swap(a[j], a[j-1]);
                k--;
            }
        }
    }

    cout << a << endl;

    return 0;
}