#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    
    long long total_money = 0;
    long long apples = 1;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        if (s == "halfplus") {
            total_money += (apples * p) / 2;
            apples = (2 * apples) + 1;
        } else {
            total_money += (apples / 2) * p;
            apples *= 2;
        }
    }

    cout << total_money << endl;

    return 0;
}