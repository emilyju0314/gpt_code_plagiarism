#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        vector<int> x_values;
        for(int i = 2; i <= n; i++) {
            if(n % i == 0) {
                x_values.push_back(i);
            }
        }

        cout << x_values.size() << endl;
        for(int x : x_values) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}