#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int clockwise = 0, anticlockwise = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '>') clockwise++;
            else if(s[i] == '<') anticlockwise++;
        }

        int returnable = 0;
        for(int i = 0; i < n; i++) {
            if(clockwise == 0 || anticlockwise == 0) {
                returnable = n;
                break;
            }
            if(s[i] == '-') {
                returnable++;
            }
        }

        cout << returnable << endl;
    }

    return 0;
}