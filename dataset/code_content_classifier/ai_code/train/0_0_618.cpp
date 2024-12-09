#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a;
        cin >> a;
        
        vector<pair<int, int>> steps;
        
        char current_char = a[0];
        int start = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] != current_char) {
                steps.push_back({start+1, i+1});
                start = i;
                current_char = a[i];
            }
        }
        
        cout << steps.size() << endl;
        for (int i = 0; i < steps.size(); i++) {
            cout << steps[i].first << " " << steps[i].second << endl;
        }
    }

    return 0;
}