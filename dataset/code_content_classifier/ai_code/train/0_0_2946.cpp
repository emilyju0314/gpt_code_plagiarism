#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int countBeautifulSubmatrices(int n, int m, vector<string>& matrix) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        unordered_map<string, int> frequencyMap;
        for (int j = i; j < n; j++) {
            frequencyMap.clear();
            string current = "";
            frequencyMap[current]++;
            for (int k = 0; k < m; k++) {
                current += matrix[j][k];
                frequencyMap[current]++;
            }
            for (int k = 0; k < current.size(); k++) {
                int total = 0;
                unordered_map<char, int> freq;
                freq[current[k]] = 1;
                for (int x = j-1; x >= i; x--) {
                    freq[matrix[x][k]]++;
                    total += (freq[matrix[x][k]] % 2 == 1) ? 1 : -1;
                }
                if (total <= 1) {
                    count++;
                }
                for (int x = k+1; x < current.size(); x++) {
                    freq[current[x]]++;
                    total += (freq[current[x]] % 2 == 1) ? 1 : -1;
                    if (total <= 1) {
                        count++;
                    }
                }
            }
        }
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    
    int beautifulSubmatrices = countBeautifulSubmatrices(n, m, matrix);
    cout << beautifulSubmatrices << endl;
    
    return 0;
}