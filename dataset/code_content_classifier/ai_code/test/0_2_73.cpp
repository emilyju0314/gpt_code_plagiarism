#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2.5*1e5 + 5;

int parent[MAXN];

int find_parent(int node){
    if(parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    int answer = 0;
    int components = N;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if(parent_u != parent_v){
            parent[parent_u] = parent_v;
            answer += components;
            components--;
        } else {
            answer += i;
        }   
    }

    cout << answer << endl;

    return 0;
}