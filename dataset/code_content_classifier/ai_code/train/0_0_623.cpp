#include <iostream>
#include <vector>

using namespace std;

int findDominantPiranha(vector<int>& piranhas) {
    int n = piranhas.size();
    int max_size = *max_element(piranhas.begin(), piranhas.end());
    int max_count = count(piranhas.begin(), piranhas.end(), max_size);

    for (int i = 0; i < n; i++) {
        if (piranhas[i] == max_size) {
            if ((i > 0 && piranhas[i-1] < max_size) || 
                (i < n-1 && piranhas[i+1] < max_size)) {
                return i+1;
            }
        }
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> piranhas(n);
        for (int i = 0; i < n; i++) {
            cin >> piranhas[i];
        }

        int result = findDominantPiranha(piranhas);
        cout << result << endl;
    }

    return 0;
}