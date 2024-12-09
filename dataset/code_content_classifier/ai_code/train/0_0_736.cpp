#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> colors(n);
    
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    
    vector<int> count(n, 0);
    
    for(int i = 0; i < n; i++) {
        vector<int> freq(n, 0);
        
        int maxFreq = 0;
        int maxColor = colors[i];
        
        for(int j = i; j < n; j++) {
            freq[colors[j]-1]++;
            if(freq[colors[j]-1] > maxFreq) {
                maxFreq = freq[colors[j]-1];
                maxColor = colors[j];
            }
            
            count[maxColor-1]++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << count[i] << " ";
    }
    
    return 0;
}