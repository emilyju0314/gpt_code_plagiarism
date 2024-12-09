#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;

vector<int> v;

int main() {
    int tes;
    scanf("%d",&tes);
    while(tes--) {
        int n,k;
        cin>>n>>k;
        for(int i =1;i<=n;i++) {
            if(i<k && k-i <= i) v.push_back(i);
            if(i > k) v.push_back(i);
        }
        printf("%d\n", v.size());
        for(int i = 0;i<v.size();i++) {
            printf("%d", v[i]);
            if(i != v.size()-1)printf(" ");
            else printf("\n");
        }
        v.clear();
    }
    return 0;
}