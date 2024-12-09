#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        string a, b;
        cin >> a >> b;

        int k = 0;
        vector<int> prefixes;

        for(int i = n-1; i >= 0; i--) {
            if(a[i] != b[i]) {
                if(a[0] != b[i]) {
                    k++;
                    prefixes.push_back(1);
                    reverse(a.begin(), a.end());
                } else {
                    k++;
                    prefixes.push_back(i+1);
                    string temp = a.substr(0, i+1);
                    reverse(temp.begin(), temp.end());
                    for(int j = 0; j <= i; j++) {
                        a[j] = temp[j];
                    }
                }
            }
        }

        cout << k << " ";
        for(int prefix : prefixes) {
            cout << prefix << " ";
        }
        cout << endl;
    }

    return 0;
}