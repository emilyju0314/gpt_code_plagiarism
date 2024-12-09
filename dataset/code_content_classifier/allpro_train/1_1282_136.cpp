#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;
 
int main()
{
    int H, W;
    cin>>H>>W;
    vector<int> A(H), B(H);
    for (int y=0; y<H; y++)
    {
        cin>>A[y]>>B[y];
        A[y]--;
    }
 
    set<pair<int, int>> S;
    multiset<int> T;
    for (int x=0; x<W; x++)
    {
        S.insert({x, 0});
        T.insert(0);
    }
 
    for (int y=0; y<H; y++)
    {
        int t = 999999;
        for (auto s=S.lower_bound({A[y], 0}); s!=S.end() && s->first<B[y]; s=S.erase(s))
        {
            T.erase(T.find(s->second)); 
            t = min(t, s->second+(B[y]-s->first));
        }
        if (B[y]<W && t<999999)
        {
            S.insert({B[y], t});
            T.insert(t);
        }
 
        if (T.empty())
            cout<<-1<<endl;
        else
            cout<<*T.begin()+y+1<<endl;
    }
}
