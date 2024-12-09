#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    string seats;
    cin >> seats;
    
    vector<int> dp_a(n+1, 0);
    vector<int> dp_b(n+1, 0);
    
    dp_a[1] = (seats[0] == '.') ? 1 : 0;
    dp_b[1] = (seats[0] == '.') ? 1 : 0;
    
    for (int i = 2; i <= n; i++) {
        if (seats[i-1] == '.') {
            dp_a[i] = dp_b[i-1] + ((i - a >= 0) ? dp_a[i-a] : 0);
            dp_b[i] = dp_a[i-1] + ((i - b >= 0) ? dp_b[i-b] : 0);
        }
    }
    
    int max_students = max(dp_a[n], dp_b[n]);
    
    cout << max_students << endl;
    
    return 0;
}