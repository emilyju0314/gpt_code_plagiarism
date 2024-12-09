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

        vector<int> operations;
        int cnt = 0;
        
        // Find the first occurrence of the character c in the string
        int first_occurrence = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                first_occurrence = i;
                break;
            }
        }

        // Number of operations required depends on the position of the first occurrence of c
        if(first_occurrence == -1) {
            for(int i = 2; i <= n; i++) {
                if(n % i == 0) {
                    operations.push_back(i);
                    cnt++;
                }
            }
        } else {
            for(int i = 2; i <= n; i++) {
                if(n % i == 0 && i != first_occurrence + 1) {
                    operations.push_back(i);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
        for(int i = 0; i < operations.size(); i++) {
            cout << operations[i] << " ";
        }
        cout << endl;
    }

    return 0;
}