#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<int, vector<int>> indices;
    for(int i = 0; i < n; i++){
        indices[a[i]].push_back(i);
    }

    while(m--){
        int queryType;
        cin >> queryType;
        
        if(queryType == 1){
            int l, r, k;
            cin >> l >> r >> k;
            l--; r--;

            vector<int> freq;
            for(int i = 0; i < 100001; i++){
                if(indices.count(i)){
                    for(int idx : indices[i]){
                        if(idx >= l && idx <= r){
                            freq.push_back(i);
                            break;
                        }
                    }
                }
            }

            if(freq.size() < k){
                cout << -1 << endl;
            } else {
                sort(freq.begin(), freq.end());
                int left = 0, right = 0, ans = 1000000000;
                map<int, int> cnt;
                for(; left < freq.size(); left++){
                    while(right < freq.size() && cnt.size() < k){
                        cnt[freq[right]]++;
                        right++;
                    }
                    if(cnt.size() == k){
                        ans = min(ans, freq[right-1] - freq[left]);
                    }
                    if(--cnt[freq[left]] == 0){
                        cnt.erase(freq[left]);
                    }
                }
                cout << ans << endl;
            }
        } else {
            int p, x;
            cin >> p >> x;
            p--;

            indices[a[p]].erase(find(indices[a[p]].begin(), indices[a[p]].end(), p));
            indices[x].push_back(p);
            a[p] = x;
        }
    }

    return 0;
}