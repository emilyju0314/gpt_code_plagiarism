#include <bits/stdc++.h>

using namespace std;

struct adat{
    int l, r;
    adat(){}
    adat(int l, int r) : l(l), r(r) {}
    bool operator < (const adat &d) const{
        return r < d.l;
    }
};

vector<vector<int>> g1, g2;
vector<int> h1, h2;
set<adat> pontok;

int ido;
void bejar(vector<vector<int>> &g, int akt){
    //cout<<akt<<" "<<ido<<" pont\n";
    h1[akt] = ido++;
    for(int x : g[akt])
        bejar(g, x);
    h2[akt] = ido++;
}

bool benne(adat a, adat b){
    return a.l < b.l && b.r < a.r;
}

vector<pair<adat, adat>> elott;
void add(int x){
    auto it = pontok.find({h1[x], h2[x]});
    if(it == pontok.end()){
        pontok.insert({h1[x], h2[x]});
        elott.push_back(make_pair(adat(h1[x], h2[x]), adat(-1, -1)));
    } else if(benne(*it, {h1[x], h2[x]})){
        elott.push_back(make_pair(adat(h1[x], h2[x]), *it));
        pontok.erase(it);
        pontok.insert({h1[x], h2[x]});
    } else
        elott.push_back(make_pair(adat(-1, -1), adat(-1, -1)));
}

void vissza(){
    if(elott.size() == 0) return;
    if(elott.back().first.l != -1)
        pontok.erase(elott.back().first);
    if(elott.back().second.l != -1)
        pontok.insert(elott.back().second);
    elott.pop_back();
}

int meg;
void bejar2(vector<vector<int>> &g, int akt){
    add(akt);
    for(int x : g[akt])
        bejar2(g, x);
    meg = max(meg, (int)pontok.size());
    vissza();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        h1.resize(n);
        h2.resize(n);
        g1.assign(n, vector<int>());
        g2.assign(n, vector<int>());
        for(int i = 1; i < n; i++){
            int a;
            cin>>a;
            g1[a-1].push_back(i);
        }
        for(int i = 1; i < n; i++){
            int a;
            cin>>a;
            g2[a-1].push_back(i);
        }

        ido = meg = 0;
        bejar(g2, 0);
        bejar2(g1, 0);

        /*for(int i = 0; i < n; i++)
            cout<<h1[i]<<" "<<h2[i]<<"\n";*/

        cout<<meg<<"\n";
    }

    return 0;
}
