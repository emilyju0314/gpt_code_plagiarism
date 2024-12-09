#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> chemicals(n);
    for(int i=0; i<n; i++){
        cin >> chemicals[i];
    }
    
    int countSegments = 0;
    for(int i=0; i<n; i++){
        long long sum = 0;
        for(int j=i; j<n; j++){
            sum += chemicals[j];
            if (sum == 0 || (k == 1 && sum == 1) || (k == -1 && sum == -1) || (k != 1 && k != -1 && (pow(k, round(log(abs(sum))/log(abs(k)))) == abs(sum)))) {
                countSegments++;
            }
        }
    }
    
    cout << countSegments << endl;
    
    return 0;
}