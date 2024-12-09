#include <iostream>
#include <string>
using namespace std;

int main() {
    string commands;
    int n;
    
    cin >> commands;
    cin >> n;
    
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int dist = 0;
        int cnt = 0;
        for (int j = 0; j < commands.size(); j++) {
            if (commands[j] == 'T') {
                cnt++;
                if (cnt == i) {
                    dist += 1;
                } else {
                    dist -= 1;
                }
            } else {
                dist += 1;
            }
        }
        ans = max(ans, abs(dist));
    }
    
    cout << ans << endl;
    
    return 0;
}