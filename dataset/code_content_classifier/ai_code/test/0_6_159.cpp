#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> subset;
    int size = 0;
    
    vector<int> factorial_count(n+1, 0);
    vector<int> factorial_sums(n+1, 0);
    
    for(int i = 2; i <= n; i++) {
        if(factorial_count[i] == 0) {
            for(int j = i; j <= n; j += i) {
                int count = 0;
                int num = j;
                while(num % i == 0) {
                    count++;
                    num /= i;
                }
                factorial_count[j] += count;
                factorial_sums[j] += count;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(factorial_sums[i] % 2 == 0) {
            subset.push_back(i);
            size++;
        }
    }
    
    cout << size << endl;
    for(int num : subset) {
        cout << num << " ";
    }

    return 0;
}