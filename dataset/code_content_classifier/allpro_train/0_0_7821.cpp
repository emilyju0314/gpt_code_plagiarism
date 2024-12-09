#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string coord;
        cin >> coord;

        if(coord[0] == 'R' && isdigit(coord[1])) {
            int idx = 1;
            while(isdigit(coord[idx])) {
                idx++;
            }

            int row = stoi(coord.substr(1, idx - 1));
            int col = stoi(coord.substr(idx + 1));

            string ans = "";
            while(col > 0) {
                if(col % 26 == 0) {
                    ans = 'Z' + ans;
                    col = col / 26 - 1;
                } else {
                    ans = char('A' + (col % 26) - 1) + ans;
                    col /= 26;
                }
            }

            cout << ans << row << endl;
        } else {
            int idx = 0;
            while(isalpha(coord[idx])) {
                idx++;
            }

            int col = 0;
            for(int j = 0; j < idx; j++) {
               col = col * 26 + (coord[j] - 'A' + 1); 
            }
            
            string row = coord.substr(idx);
            cout << "R" << row << "C" << col << endl;
        }
    }

    return 0;
}