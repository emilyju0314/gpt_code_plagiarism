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
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                if(i % 2 == 0) {
                    x_values.push_back(2);
                    count++;
                }
            }
        }

        if(count == 0) {
            cout << "0" << endl;
        } else {
            cout << count << endl;
            for(int x : x_values) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}