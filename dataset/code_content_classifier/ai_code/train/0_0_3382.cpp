#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> divisors(n);
    for(int i = 0; i < n; i++) {
        cin >> divisors[i];
    }

    sort(divisors.begin(), divisors.end());

    int x = divisors.back();
    for(int i = 0; i < n-1; i++) {
        if(x % divisors[i] != 0) {
            int y = divisors[i];
            for(int j = i+1; j < n-1; j++) {
                if(y % divisors[j] == 0) {
                    y /= divisors[j];
                }
            }
            x /= y;
            break;
        }
    }

    cout << x << " " << divisors.back() << endl;

    return 0;
}