#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> friends(n);
    
    for(int i = 0; i < n; i++) {
        cin >> friends[i];
    }
    
    int count = 0;
    for(int i = 1; i <= 5; i++) {
        int sum = i;
        for(int j = 0; j < n; j++) {
            sum += friends[j];
        }
        if(sum % (n+1) != 1) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}