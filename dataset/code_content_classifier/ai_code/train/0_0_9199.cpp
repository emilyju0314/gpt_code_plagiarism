#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int ones = 0, zeros = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && a[i] == 1){
                ones++;
            } else if (i % 2 == 1 && a[i] == 0){
                zeros++;
            }
        }

        int m = n / 2;
        int count = 0;
        for(int i = 0; i < n; i++){
            if (i % 2 == 0 && zeros > m){
                if(a[i] == 1){
                    count++;
                    ans.push_back(0);
                    zeros--;
                } else {
                    ans.push_back(a[i]);
                }
            } else if (i % 2 == 1 && ones > m){
                if(a[i] == 0){
                    count++;
                    ans.push_back(1);
                    ones--;
                } else {
                    ans.push_back(a[i]);
                }
            } else {
                ans.push_back(a[i]);
            }
        }

        cout << count << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}