#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        vector<int> pipes(n);
        vector<int> joints(n-1);
        
        for (int i = 0; i < n; i++) {
            cin >> pipes[i];
        }
        
        for (int i = 0; i < n-1; i++) {
            cin >> joints[i];
        }
        
        unsigned long long salary = 0;
        unsigned long long total_length = 0;

        for (int i = 0; i < n; i++) {
            total_length += pipes[i];
        }
        
        for (int i = 0; i < n-1; i++) {
            total_length += joints[i];
        }
        
        for (int i = 0; i < n; i++) {
            salary += pipes[i] * total_length;
            total_length -= pipes[i];
        }
        
        cout << salary << endl;
        
        cin >> n;
    }

    return 0;
}